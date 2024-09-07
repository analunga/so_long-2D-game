/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:45:17 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:31:18 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	setup_map_environment(t_game *game)
{
	if (!allocate_and_initialize_map(game, game->map_width, game->map_height))
		return (false);
	place_walls(game, game->map_width, game->map_height);
	if (!place_player(game, game->map_width, game->map_height))
		return (false);
	locate_player(game);
	return (true);
}

bool	set_exit_position(t_game *game)
{
	t_coords	coords;
	int			ex;
	int			ey;

	if (!place_exit(game))
		return (false);
	locate_exit(game);
	ex = game->exit_x;
	ey = game->exit_y;
	coords.px = game->player_x;
	coords.py = game->player_y;
	coords.ex = ex;
	coords.ey = ey;
	if (!is_exit_reachable(game, coords))
	{
		ft_printf("Error: Exit is not reachable from player's position.\n");
		return (false);
	}
	return (true);
}

bool	generate_map(t_game *game, int width, int height)
{
	srand(time(NULL));
	game->map_width = width;
	game->map_height = height;
	if (!setup_map_environment(game))
		return (false);
	if (!set_exit_position(game))
		return (false);
	place_collectibles(game, game->map_width, game->map_height);
	return (true);
}
