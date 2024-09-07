/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:11:03 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:17:50 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	get_window_width(t_game *game)
{
	return (game->map_width * TILE_SIZE);
}

int	get_window_height(t_game *game)
{
	return (game->map_height * TILE_SIZE);
}

void	window_resize_callback(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_resize(width, height, game);
}
