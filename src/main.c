/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:26:30 by analunga          #+#    #+#             */
/*   Updated: 2024/09/07 22:30:41 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	handle_args(argc, argv, &game);
	set_map_dimensions(&game);
	validate_and_locate(&game);
	if (!initialize_game(&game))
	{
		ft_printf("Failed to initialize game\n");
		clean_game(&game);
		return (1);
	}
	init_mlx(&game);
	draw_map(&game);
	mlx_loop(game.mlx);
	clean_game(&game);
	return (0);
}
