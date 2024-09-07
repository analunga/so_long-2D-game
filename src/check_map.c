/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:57:47 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:07:17 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

bool	is_within_bounds(t_game *game, int x, int y)
{
	return (x >= 0 && y >= 0 && x < game->map_width && y < game->map_height);
}

bool	is_wall(t_game *game, int x, int y)
{
	return (game->map[y][x] == WALL);
}

bool	is_wall_or_platform(t_game *game, int x, int y)
{
	return (game->map[y][x] == WALL || game->map[y][x] == PLATFORM);
}

void	collect_item(t_game *game, int x, int y)
{
	game->collectibles_collected++;
	game->collectibles--;
	game->map[y][x] = EMPTY;
	draw_tile(game, EMPTY, x, y);
	ft_printf("Collectible collected! Remaining: %d\n", game->collectibles);
}

void	check_exit_condition(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == EXIT && game->collectibles == 0)
	{
		game->game_over = true;
		game->game_won = true;
		ft_printf("Congratulations! You won!\n");
	}
}
