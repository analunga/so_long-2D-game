/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:15:43 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 00:23:25 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

bool	check_top_bottom_rows(t_game *game, int row)
{
	int	col;

	col = 0;
	while (col < game->map_width)
	{
		if (game->map[row][col] != WALL)
			return (false);
		col++;
	}
	return (true);
}

bool	check_left_right_cols(t_game *game, int col)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != WALL || game->map[i][col - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	perform_dfs(t_game *game, t_coords player, t_coords exit)
{
	t_coords	next;

	if (player.x < 0 || player.x >= game->map_width
		|| player.y < 0 || player.y >= game->map_height
		|| game->map[player.y][player.x] == WALL)
		return (false);
	if (player.x == exit.x && player.y == exit.y)
		return (true);
	game->map[player.y][player.x] = WALL;
	ft_memcpy(&next, &player, sizeof(t_coords));
	next.x = player.x + 1;
	if (perform_dfs(game, next, exit))
		return (true);
	next.x = player.x - 1;
	if (perform_dfs(game, next, exit))
		return (true);
	next.x = player.x;
	next.y = player.y + 1;
	if (perform_dfs(game, next, exit))
		return (true);
	next.y = player.y - 1;
	if (perform_dfs(game, next, exit))
		return (true);
	return (false);
}

bool	dfs_mark_visited(t_game *game, t_coords pos)
{
	char		temp;
	t_coords	invalid_coords;

	temp = game->map[pos.y][pos.x];
	game->map[pos.y][pos.x] = WALL;
	ft_memset(&invalid_coords, -1, sizeof(t_coords));
	if (perform_dfs(game, pos, invalid_coords))
	{
		return (true);
	}
	game->map[pos.y][pos.x] = temp;
	return (false);
}
