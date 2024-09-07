/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:10:02 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 00:21:53 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	delete_background(t_game *game)
{
	if (game->background_img)
	{
		mlx_delete_image(game->mlx, game->background_img);
		mlx_delete_texture(game->background_texture);
	}
}

static bool	load_and_resize_background(int width, int height, t_game *game)
{
	if (load_background(game, "./assets/background.png"))
	{
		return (resize_and_display_background(width, height, game));
	}
	return (false);
}

void	handle_resize(int width, int height, t_game *game)
{
	if (width != get_window_width(game) || height != get_window_height(game))
	{
		update_map_dimensions(width, height, game);
		delete_background(game);
		if (load_and_resize_background(width, height, game))
		{
			update_game_image(width, height, game);
		}
	}
}
