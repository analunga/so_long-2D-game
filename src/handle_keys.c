/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:30:00 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 22:43:23 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->game_over)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_player(game, 0, -1);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_player(game, 0, 1);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_player(game, -1, 0);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_player(game, 1, 0);
	draw_map(game);
}

void	init_mlx(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, draw_map, game);
	mlx_resize_hook(game->mlx, window_resize_callback, game);
	clear_entire_screen(game);
	draw_player(game);
}

void	handle_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Error: Incorrect number of arguments\n");
		exit(1);
	}
	game->map = read_map(argv[1]);
	if (!game->map)
	{
		ft_printf("Error: Failed to load map '%s'\n", argv[1]);
		exit(1);
	}
}

void	set_map_dimensions(t_game *game)
{
	int	row_index;
	int	current_width;

	if (!game || !game->map || !game->map[0])
	{
		game->map_width = 0;
		game->map_height = 0;
		return ;
	}
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	row_index = 1;
	while (row_index < game->map_height)
	{
		current_width = ft_strlen(game->map[row_index]);
		if (current_width != game->map_width)
		{
			ft_printf("Error: Map is not rectangular at row %d\n", row_index);
			break ;
		}
		row_index++;
	}
}

void	validate_and_locate(t_game *game)
{
	if (!validate_map(game->map, game->map_height, game->map_width, game))
	{
		ft_printf("Error: Invalid map\n");
		clean_game(game);
		exit(1);
	}
	locate_player(game);
}
