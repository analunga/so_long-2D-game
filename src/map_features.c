/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_features.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:36:23 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 22:20:34 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	fill_map_with_empty(t_game *game, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			game->map[y][x] = EMPTY;
			x++;
		}
		y++;
	}
}

void	add_walls(t_game *game, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		game->map[0][x] = WALL;
		game->map[height - 1][x] = WALL;
		x++;
	}
	y = 0;
	while (y < height)
	{
		game->map[y][0] = WALL;
		game->map[y][width - 1] = WALL;
		y++;
	}
}

void	add_platforms_row(t_game *game, int width, int y)
{
	int	platform_x1;
	int	platform_x2;

	platform_x1 = 1 + rand() % (width / 2 - 2);
	platform_x2 = width / 2 + rand() % (width / 2 - 2);
	if (game->map[y][platform_x1] == EMPTY)
		game->map[y][platform_x1] = PLATFORM;
	if (game->map[y][platform_x2] == EMPTY)
		game->map[y][platform_x2] = PLATFORM;
}

void	add_platforms(t_game *game, int width, int height)
{
	int	y;

	y = 2;
	while (y < height - 2)
	{
		add_platforms_row(game, width, y);
		y += 2;
	}
}

bool	is_surrounded_by_walls(char **map, int rows, int cols)
{
	int	col;
	int	row;

	col = 0;
	while (col < cols)
	{
		if (map[0][col] != WALL || map[rows - 1][col] != WALL)
			return (false);
		col++;
	}
	row = 0;
	while (row < rows)
	{
		if (map[row][0] != WALL || map[row][cols - 1] != WALL)
			return (false);
		row++;
	}
	return (true);
}
