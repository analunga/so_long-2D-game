/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:28:18 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 01:07:19 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_map(char **map, int rows, int cols, t_game *game)
{
	if (!is_surrounded_by_walls(map, rows, cols))
	{
		ft_printf("Error: Map is not surrounded by walls\n");
		return (false);
	}
	if (!is_rectangular_map(map, rows))
	{
		ft_printf("Error: Map is not rectangular\n");
		return (false);
	}
	if (!has_required_elements_helper(map, rows, cols, game))
	{
		ft_printf("Error: Map does not have all required elements\n");
		return (false);
	}
	return (true);
}
