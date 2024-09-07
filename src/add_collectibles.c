/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_collectibles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:19:05 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 22:23:36 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static bool	is_valid_position(t_game *game, int x, int y)
{
	return (game->map[y][x] == EMPTY || game->map[y][x] == PLATFORM);
}

static void	placement_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == PLATFORM)
	{
		if (y > 1 && game->map[y - 1][x] == EMPTY)
		{
			game->map[y - 1][x] = COLLECTIBLE;
			game->collectibles++;
		}
	}
	else
	{
		game->map[y][x] = COLLECTIBLE;
		game->collectibles++;
	}
}

void	add_collectibles(t_game *game, int width, int height)
{
	int		num_collectibles;
	int		x;
	int		y;
	int		i;
	bool	position_valid;

	num_collectibles = (width * height) / 20;
	i = 0;
	while (i < num_collectibles)
	{
		position_valid = false;
		while (!position_valid)
		{
			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;
			position_valid = is_valid_position(game, x, y);
		}
		placement_collectible(game, x, y);
		i++;
	}
}
