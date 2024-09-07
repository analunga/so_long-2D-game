/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:30:59 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 21:19:22 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(mlx_texture_t **textures, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (textures[i])
		{
			mlx_delete_texture(textures[i]);
			textures[i] = NULL;
		}
		i++;
	}
}

void	clean_images(mlx_t *mlx, mlx_image_t **images, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (images[i])
		{
			mlx_delete_image(mlx, images[i]);
			images[i] = NULL;
		}
		i++;
	}
}

void	clean_game_map(char **map, int rows)
{
	int	i;

	if (map)
	{
		i = 0;
		while (i < rows)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	clean_texture_and_image(mlx_t *mlx, mlx_texture_t *texture,
	mlx_image_t *image)
{
	if (texture)
		mlx_delete_texture(texture);
	if (image)
		mlx_delete_image(mlx, image);
}

void	clean_player_textures_and_images(t_game *game)
{
	int	dir;
	int	frame;

	dir = 0;
	while (dir < 4)
	{
		frame = 0;
		while (frame < 3)
		{
			clean_texture_and_image(game->mlx,
				game->player_textures[dir][frame],
				game->player_images[dir][frame]);
			frame++;
		}
		dir++;
	}
}
