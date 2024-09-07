/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_reachable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:26:49 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:56:37 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_adjacent_cells(t_game *game, t_coords pos)
{
	t_coords	adj_pos;

	adj_pos.x = pos.x + 1;
	adj_pos.y = pos.y;
	adj_pos.ex = -1;
	adj_pos.ey = -1;
	if (dfs_mark_visited(game, adj_pos))
	{
		return (true);
	}
	adj_pos.x = pos.x - 1;
	if (dfs_mark_visited(game, adj_pos))
	{
		return (true);
	}
	adj_pos.x = pos.x;
	adj_pos.y = pos.y + 1;
	if (dfs_mark_visited(game, adj_pos))
	{
		return (true);
	}
	adj_pos.y = pos.y - 1;
	if (dfs_mark_visited(game, adj_pos))
		return (true);
	return (false);
}

bool	is_exit_reachable(t_game *game, t_coords coords)
{
	t_coords	player;
	t_coords	exit;

	player.x = coords.x;
	player.y = coords.y;
	player.ex = -1;
	player.ey = -1;
	exit.x = coords.ex;
	exit.y = coords.ey;
	exit.ex = -1;
	exit.ey = -1;
	if (perform_dfs(game, player, exit))
	{
		return (true);
	}
	return (check_adjacent_cells(game, player));
}
