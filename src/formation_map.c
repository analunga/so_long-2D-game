/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formation_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:39:26 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 22:01:22 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	place_exit(t_game *game)
{
	int	ex;
	int	ey;

	ex = rand() % (game->map_width - 2) + 1;
	ey = rand() % (game->map_height - 2) + 1;
	while (game->map[ey][ex] != EMPTY
		|| (ex == game->player_x && ey == game->player_y))
	{
		ex = rand() % (game->map_width - 2) + 1;
		ey = rand() % (game->map_height - 2) + 1;
	}
	game->map[ey][ex] = EXIT;
	return (true);
}

bool	place_collectible(t_game *game, int cx, int cy)
{
	if (game->map[cy][cx] == EMPTY)
	{
		game->map[cy][cx] = COLLECTIBLE;
		game->collectibles++;
		return (true);
	}
	return (false);
}

void	place_collectibles(t_game *game, int width, int height)
{
	int	num_collectibles;
	int	cx;
	int	cy;

	num_collectibles = (width * height) / 20;
	while (num_collectibles > 0)
	{
		cx = rand() % (width - 2) + 1;
		cy = rand() % (height - 2) + 1;
		if (place_collectible(game, cx, cy))
			num_collectibles--;
	}
}
