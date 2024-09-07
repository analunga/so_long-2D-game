/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:08:51 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 23:15:30 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

bool	load_texture(char *path, mlx_texture_t **texture,
	mlx_image_t **image, t_game *game)
{
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		ft_printf("Failed to load texture from %s\n", path);
		return (false);
	}
	*image = mlx_texture_to_image(game->mlx, *texture);
	if (!*image)
	{
		ft_printf("Failed to create image from texture\n");
		mlx_delete_texture(*texture);
		*texture = NULL;
		return (false);
	}
	return (true);
}

static bool	load_textures_for_direction(t_game *game, int dir)
{
	int		frame;
	char	*player_files[3];

	player_files[0] = "./assets/1.png";
	player_files[1] = "./assets/2.png";
	player_files[2] = "./assets/3.png";
	frame = 0;
	while (frame < 3)
	{
		if (!load_texture(player_files[frame],
				&game->player_textures[dir][frame],
			&game->player_images[dir][frame], game))
		{
			ft_printf("Failed player direction %d,frame %d.\n", dir, frame);
			return (false);
		}
		frame++;
	}
	return (true);
}

bool	load_player_textures(t_game *game)
{
	int	dir;

	dir = 0;
	while (dir < 4)
	{
		if (!load_textures_for_direction(game, dir))
			return (false);
		dir++;
	}
	game->current_player_direction = 0;
	game->current_player_frame = 0;
	return (true);
}

bool	load_collectible_textures(t_game *game)
{
	char	*collectible_files[COLLECTIBLE_FRAMES];
	int		i;

	collectible_files[0] = "./assets/collectible1.png";
	collectible_files[1] = "./assets/collectible2.png";
	i = 0;
	while (i < COLLECTIBLE_FRAMES)
	{
		if (!load_texture(collectible_files[i], &game->collectible_textures[i],
				&game->collectible[i], game))
		{
			ft_printf("Failed to load collectible texture %d.\n", i);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	load_platform_textures(t_game *game)
{
	char	*platform_files[PLATFORM_FRAMES];
	int		i;

	platform_files[0] = "./assets/platform1.png";
	platform_files[1] = "./assets/platform2.png";
	i = 0;
	while (i < PLATFORM_FRAMES)
	{
		if (!load_texture(platform_files[i], &game->platform_textures[i],
				&game->platform_images[i], game))
		{
			ft_printf("Failed to load platform texture %d.\n", i);
			return (false);
		}
		i++;
	}
	return (true);
}
