/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:29:25 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 21:37:39 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_screen(t_game *game)
{
	uint32_t	color;
	size_t		total_pixels;

	color = 0x00000000;
	if (game->img)
	{
		color = game->background_color;
		total_pixels = game->img->width * game->img->height;
		ft_memset(game->img->pixels, color, total_pixels * sizeof(uint32_t));
		mlx_image_to_window(game->mlx, game->img, 0, 0);
	}
}

void	draw_tile(t_game *game, char tile_type, int x, int y)
{
	mlx_image_t	*image;
	int			draw_x;
	int			draw_y;

	draw_x = x * TILE_SIZE;
	draw_y = y * TILE_SIZE;
	if (tile_type == WALL)
		image = game->wall_img;
	else if (tile_type == COLLECTIBLE)
	{
		if (game->map[y][x] == COLLECTIBLE)
			image = game->collectible[game->current_collectible_frame];
		else
			image = NULL;
	}
	else if (tile_type == EXIT)
		image = game->exit_img;
	else if (tile_type == PLATFORM)
		image = game->platform_images[game->current_platform_frame];
	else
		image = NULL;
	if (image)
		mlx_image_to_window(game->mlx, image, draw_x, draw_y);
}

void	draw_map_tiles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

static void	update_animations(t_game *game)
{
	game->current_collectible_frame++;
	if (game->current_collectible_frame >= COLLECTIBLE_FRAMES)
		game->current_collectible_frame = 0;
	game->current_platform_frame++;
	if (game->current_platform_frame >= PLATFORM_FRAMES)
		game->current_platform_frame = 0;
}

void	draw_map(void *param)
{
	t_game	*game;
	int		trophy_x;
	int		trophy_y;

	game = (t_game *)param;
	if (!game || !game->mlx || !game->map)
		return ;
	clear_screen(game);
	draw_map_tiles(game);
	if (game->player_img)
		mlx_image_to_window(game->mlx, game->player_img,
			game->player_x, game->player_y);
	update_animations(game);
	if (game->game_won && game->trophy_img)
	{
		trophy_x = (game->map_width * TILE_SIZE
				- game->trophy_img->width) / 2;
		trophy_y = (game->map_height * TILE_SIZE
				- game->trophy_img->height) / 2;
		mlx_image_to_window(game->mlx, game->trophy_img, trophy_x, trophy_y);
	}
}
