/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:15:07 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 01:08:42 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_move_count(t_game *game)
{
	char	move_count_str[50];

	snprintf(move_count_str, sizeof(move_count_str), "Moves: %d",
		game->move_count);
	render_text(game, move_count_str, 10, 10);
}

bool	load_cover_texture(t_game *game)
{
	game->cover_texture = mlx_load_png("./assets/cover.png");
	if (!game->cover_texture)
	{
		ft_printf("Error: Failed to load cover texture\n");
		return (false);
	}
	game->cover_img = mlx_texture_to_image(game->mlx, game->cover_texture);
	if (!game->cover_img)
	{
		ft_printf("Error: Failed to create cover image from texture\n");
		mlx_delete_texture(game->cover_texture);
		return (false);
	}
	return (true);
}

bool	is_rectangular_map(char **map, int rows)
{
	int		i;
	int		row_length;

	if (rows == 0)
		return (true);
	row_length = ft_strlen(map[0]);
	i = 1;
	while (i < rows)
	{
		if ((int)ft_strlen(map[i]) != row_length)
		{
			ft_printf("Error: Map is not rectangular.\n"
				"Row %d has a different length.\n", i);
			return (false);
		}
		i++;
	}
	return (true);
}
