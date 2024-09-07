/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:50:13 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 00:54:33 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_invalid_char(char c)
{
	return (c != EMPTY && c != WALL && c != PLATFORM
		&& c != PLAYER && c != COLLECTIBLE && c != EXIT);
}

static bool	handle_cell(char c, t_handle_cell_params params)
{
	if (c == PLAYER)
	{
		(*(params.player_count))++;
		params.game->player_x = params.x;
		params.game->player_y = params.y;
	}
	else if (c == COLLECTIBLE)
		params.game->collectibles++;
	else if (c == EXIT)
		(*(params.exit_count))++;
	else if (is_invalid_char(c))
	{
		ft_printf("Error: Invalid character '%c' at (%d, %d)\n",
			c, params.x, params.y);
		return (false);
	}
	return (true);
}

static bool	process_row(char *row, int cols, int row_index,
	t_handle_cell_params params)
{
	int	j;

	j = 0;
	while (j < cols)
	{
		params.x = j;
		params.y = row_index;
		if (!handle_cell(row[j], params))
			return (false);
		j++;
	}
	return (true);
}

bool	has_required_elements_helper(char **map, int rows,
		int cols, t_game *game)
{
	int						player_count;
	int						exit_count;
	int						i;
	t_handle_cell_params	params;

	player_count = 0;
	exit_count = 0;
	params.game = game;
	params.player_count = &player_count;
	params.exit_count = &exit_count;
	i = 0;
	while (i < rows)
	{
		if (!process_row(map[i], cols, i, params))
			return (false);
		i++;
	}
	if (player_count != 1 || exit_count != 1 || game->collectibles == 0)
		return (false);
	return (true);
}
