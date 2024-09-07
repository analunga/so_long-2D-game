/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:13:20 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 00:15:09 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_previous_background(t_game *game)
{
	if (game->background_img)
	{
		mlx_delete_image(game->mlx, game->background_img);
		mlx_delete_texture(game->background_texture);
	}
}

bool	load_new_background(t_game *game)
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
		ft_printf("Error: Failed to create background image from texture\n");
		mlx_delete_texture(game->background_texture);
		return (false);
	}
	return (true);
}

static void	draw_background_image(t_game *game, int window_width,
	int window_height)
{
	int	x;
	int	y;

	y = 0;
	while (y < window_height)
	{
		x = 0;
		while (x < window_width)
		{
			mlx_image_to_window(game->mlx, game->background_img, x, y);
			x += game->background_img->width;
		}
		y += game->background_img->height;
	}
}

void	clear_entire_screen(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = get_window_width(game);
	window_height = get_window_height(game);
	clear_previous_background(game);
	if (!load_new_background(game))
		return ;
	draw_background_image(game, window_width, window_height);
}
