/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:59:39 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:16:33 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cover_previous_position(t_game *game, int x, int y)
{
	mlx_image_t		*cover;
	uint32_t		*pixels;
	unsigned int	i;

	cover = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!cover)
	{
		ft_printf("Error: Failed to create cover image\n");
		return ;
	}
	pixels = (uint32_t *)cover->pixels;
	i = 0;
	while (i < TILE_SIZE * TILE_SIZE)
	{
		pixels[i] = game->background_color;
		i++;
	}
	mlx_image_to_window(game->mlx, cover, x * TILE_SIZE, y * TILE_SIZE);
	mlx_delete_image(game->mlx, cover);
	draw_tile(game, game->map[y][x], x, y);
}

static void	draw_tile_at(t_game *game, int x, int y, int offset)
{
	int	tile_x;
	int	tile_y;

	tile_x = (x * TILE_SIZE + offset) / TILE_SIZE;
	tile_y = (y * TILE_SIZE + offset) / TILE_SIZE;
	if (is_within_bounds(game, tile_x, tile_y))
		draw_tile(game, game->map[tile_y][tile_x], tile_x, tile_y);
}

void	clear_player_area(t_game *game, int x, int y)
{
	int	player_width;
	int	player_height;
	int	offset;

	player_width = game->player_images[game->current_player_direction]
	[game->current_player_frame]->width;
	player_height = game->player_images[game->current_player_direction]
	[game->current_player_frame]->height;
	offset = 0;
	while (offset < player_width)
	{
		draw_tile_at(game, x, y, offset);
		offset += TILE_SIZE;
	}
	offset = 0;
	while (offset < player_height)
	{
		draw_tile_at(game, x, y, offset);
		offset += TILE_SIZE;
	}
}

bool	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (!is_within_bounds(game, new_x, new_y))
		return (false);
	if (is_wall_or_platform(game, new_x, new_y))
		return (false);
	if (game->map[new_y][new_x] == COLLECTIBLE)
		collect_item(game, new_x, new_y);
	return (true);
}

void	render_text(t_game *game, const char *text, int x, int y)
{
	mlx_image_t	*text_images[10];
	int			index;

	index = text[0] - '0';
	if (index >= 0 && index < 10 && text_images[index])
		mlx_image_to_window(game->mlx, text_images[index], x, y);
}
