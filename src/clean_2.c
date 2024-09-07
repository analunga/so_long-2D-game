/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:15:56 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 21:18:18 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_collectibles_and_platforms(t_game *game)
{
	clean_textures(game->collectible_textures, COLLECTIBLE_FRAMES);
	clean_images(game->mlx, game->collectible, COLLECTIBLE_FRAMES);
	clean_textures(game->platform_textures, PLATFORM_FRAMES);
	clean_images(game->mlx, game->platform_images, PLATFORM_FRAMES);
}

void	clean_static_textures_and_images(t_game *game)
{
	clean_texture_and_image(game->mlx, game->wall_texture, game->wall_img);
	clean_texture_and_image(game->mlx, game->exit_texture, game->exit_img);
	clean_texture_and_image(game->mlx, game->trophy_texture, game->trophy_img);
	if (game->background_img)
	{
		mlx_delete_image(game->mlx, game->background_img);
		game->background_img = NULL;
	}
}

void	clean_game(t_game *game)
{
	if (game->map)
	{
		free_map(game->map, game->map_height);
		game->map = NULL;
	}
	clean_player_textures_and_images(game);
	clean_collectibles_and_platforms(game);
	clean_static_textures_and_images(game);
	if (game->background_img)
	{
		mlx_delete_image(game->mlx, game->background_img);
		game->background_img = NULL;
	}
	if (game->cover_texture)
	{
		mlx_delete_texture(game->cover_texture);
		game->cover_texture = NULL;
	}
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
}
