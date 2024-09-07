/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:51:58 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 00:23:41 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map_dimensions(int width, int height, t_game *game)
{
	game->map_width = width / TILE_SIZE;
	game->map_height = height / TILE_SIZE;
}

void	delete_existing_background(t_game *game)
{
	if (game->background_img)
	{
		mlx_delete_image(game->mlx, game->background_img);
		game->background_img = NULL;
		mlx_delete_texture(game->background_texture);
		game->background_texture = NULL;
	}
}

bool	load_background(t_game *game, const char *path)
{
	game->background_texture = mlx_load_png(path);
	if (!game->background_texture)
	{
		ft_printf("Error: Failed to load background texture\n");
		return (false);
	}
	game->background_img = mlx_texture_to_image(game->mlx,
			game->background_texture);
	if (!game->background_img)
	{
		ft_printf("Error: Failed to create background image from texture\n");
		mlx_delete_texture(game->background_texture);
		return (false);
	}
	return (true);
}

int	resize_and_display_background(int width, int height, t_game *game)
{
	if (!mlx_resize_image(game->background_img, width, height))
	{
		ft_printf("Error: Failed to resize background image\n");
		mlx_delete_image(game->mlx, game->background_img);
		mlx_delete_texture(game->background_texture);
		return (0);
	}
	mlx_image_to_window(game->mlx, game->background_img, 0, 0);
	return (1);
}

void	update_game_image(int width, int height, t_game *game)
{
	if (game->img)
	{
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_new_image(game->mlx, width, height);
		if (!game->img)
		{
			ft_printf("Error: Failed to create new game image\n");
		}
		else
		{
			mlx_image_to_window(game->mlx, game->img, 0, 0);
		}
	}
}
