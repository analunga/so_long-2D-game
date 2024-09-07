/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:22:03 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 21:54:26 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

bool	allocate_map_rows(t_game *game, int height)
{
	int	y;

	game->map = (char **)malloc(sizeof(char *) * height);
	if (game->map == NULL)
		return (false);
	y = 0;
	while (y < height)
	{
		game->map[y] = NULL;
		y++;
	}
	return (true);
}

bool	initialize_map_row(t_game *game, int y, int width)
{
	int	x;

	game->map[y] = (char *)malloc(sizeof(char) * (width + 1));
	if (game->map[y] == NULL)
	{
		while (y > 0)
			free(game->map[--y]);
		free(game->map);
		return (false);
	}
	x = 0;
	while (x < width)
	{
		if (rand() % 5 == 0)
			game->map[y][x] = WALL;
		else
			game->map[y][x] = EMPTY;
		x++;
	}
	game->map[y][width] = '\0';
	return (true);
}

bool	allocate_and_initialize_map(t_game *game, int width, int height)
{
	int	y;

	if (!allocate_map_rows(game, height))
		return (false);
	y = 0;
	while (y < height)
	{
		if (!initialize_map_row(game, y, width))
			return (false);
		y++;
	}
	return (true);
}

void	place_walls(t_game *game, int width, int height)
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

bool	place_player(t_game *game, int width, int height)
{
	int	px;
	int	py;

	px = rand() % (width - 2) + 1;
	py = rand() % (height - 2) + 1;
	while (game->map[py][px] != EMPTY)
	{
		px = rand() % (width - 2) + 1;
		py = rand() % (height - 2) + 1;
	}
	game->map[py][px] = PLAYER;
	return (true);
}
