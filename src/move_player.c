/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:30:27 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:00:37 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	update_player_direction(t_game *game, int dx, int dy)
{
	if (dx < 0)
		game->current_player_direction = 1;
	else if (dx > 0)
		game->current_player_direction = 2;
	else if (dy < 0)
		game->current_player_direction = 3;
	else if (dy > 0)
		game->current_player_direction = 0;
	game->current_player_frame = (game->current_player_frame + 1) % 3;
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (is_valid_move(game, new_x, new_y))
	{
		if (game->cover_img)
		{
			mlx_image_to_window(game->mlx, game->cover_img,
				game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
		}
		game->player_x = new_x;
		game->player_y = new_y;
		update_player_direction(game, dx, dy);
		if (game->map[new_y][new_x] == COLLECTIBLE)
			collect_item(game, new_x, new_y);
		check_exit_condition(game, new_x, new_y);
		game->move_count++;
		redraw_area(game, game->player_x - 1, game->player_y - 1);
		redraw_area(game, new_x - 1, new_y - 1);
		draw_player(game);
		draw_move_count(game);
		printf("Move %d\n", game->move_count);
	}
}

void	redraw_area(t_game *game, int x, int y)
{
	int	dx;
	int	dy;
	int	tile_x;
	int	tile_y;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			tile_x = x + dx;
			tile_y = y + dy;
			if (is_within_bounds(game, tile_x, tile_y))
				draw_tile(game, game->map[tile_y][tile_x], tile_x, tile_y);
			dx++;
		}
		dy++;
	}
}

void	erase_player(t_game *game, int x, int y)
{
	mlx_image_t		*erase_img;
	uint32_t		*pixels;
	unsigned int	i;

	erase_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!erase_img)
	{
		ft_printf("Error: Failed to create erase image\n");
		return ;
	}
	pixels = (uint32_t *)erase_img->pixels;
	i = 0;
	while (i < TILE_SIZE * TILE_SIZE)
	{
		pixels[i] = game->background_color;
		i++;
	}
	mlx_image_to_window(game->mlx, erase_img, x * TILE_SIZE, y * TILE_SIZE);
	mlx_delete_image(game->mlx, erase_img);
	draw_tile(game, game->map[y][x], x, y);
}

void	draw_player(t_game *game)
{
	mlx_image_t	*player_img;
	int			draw_x;
	int			draw_y;

	player_img = game->player_images[game->current_player_direction]
	[game->current_player_frame];
	draw_x = game->player_x * TILE_SIZE;
	draw_y = game->player_y * TILE_SIZE;
	if (player_img)
		mlx_image_to_window(game->mlx, player_img, draw_x, draw_y);
	else
		printf("Error: Player image is null\n");
}
