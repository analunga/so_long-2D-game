/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:09:24 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:09:23 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

bool	load_textures(t_game *game)
{
	if (!load_texture("./assets/wall.png", &game->wall_texture,
			&game->wall_img, game))
		return (false);
	if (!load_player_textures(game))
		return (false);
	if (!load_texture("./assets/exit.png", &game->exit_texture,
			&game->exit_img, game))
		return (false);
	if (!load_texture("./assets/trophy.png", &game->trophy_texture,
			&game->trophy_img, game))
		return (false);
	if (!load_collectible_textures(game))
		return (false);
	if (!load_platform_textures(game))
		return (false);
	if (!load_cover_texture(game))
		return (false);
	return (true);
}

bool	create_game_image(t_game *game)
{
	game->img = mlx_new_image(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE);
	if (!game->img)
	{
		ft_printf("Error creating new image.\n");
		return (false);
	}
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	return (true);
}
