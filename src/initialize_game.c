/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:27:38 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 22:28:15 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static bool	setup_mlx_instance(t_game *game,
	int window_width, int window_height)
{
	game->mlx = mlx_init(window_width, window_height,
			"So Long", game->fullscreen);
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (false);
	}
	return (true);
}

static bool	load_background_image(t_game *game,
	int window_width, int window_height)
{
	game->background_texture = mlx_load_png("./assets/background.png");
	if (!game->background_texture)
	{
		ft_printf("Error: Failed to load background texture\n");
		return (false);
	}
	game->background_img = mlx_texture_to_image(game->mlx,
			game->background_texture);
	if (!game->background_img)
	{
		ft_printf("Error: Failed to create image from background texture\n");
		mlx_delete_texture(game->background_texture);
		return (false);
	}
	if (!mlx_resize_image(game->background_img, window_width, window_height))
	{
		ft_printf("Error: Failed to resize background image\n");
		mlx_delete_image(game->mlx, game->background_img);
		mlx_delete_texture(game->background_texture);
		return (false);
	}
	mlx_image_to_window(game->mlx, game->background_img, 0, 0);
	return (true);
}

static bool	handle_background_image(t_game *game, int window_width,
	int window_height)
{
	if (game->background_img)
	{
		mlx_delete_image(game->mlx, game->background_img);
		game->background_img = NULL;
		mlx_delete_texture(game->background_texture);
		game->background_texture = NULL;
	}
	return (load_background_image(game, window_width, window_height));
}

bool	initialize_game(t_game *game)
{
	int	window_width;
	int	window_height;

	game->fullscreen = false;
	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	if (!setup_mlx_instance(game, window_width, window_height))
		return (false);
	if (!handle_background_image(game, window_width, window_height))
		return (false);
	if (!load_textures(game))
	{
		ft_printf("Error: Failed to load game textures\n");
		return (false);
	}
	if (!create_game_image(game))
	{
		ft_printf("Error: Failed to create game image\n");
		return (false);
	}
	return (true);
}
