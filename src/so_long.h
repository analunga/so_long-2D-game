/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:25:52 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 01:09:27 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define TILE_SIZE 50
# define MAX_MAP_SIZE 128
# define PLAYER_WALK_FRAMES 7
# define COLLECTIBLE_FRAMES 2
# define PLATFORM_FRAMES 2
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define START 'P'
# define PLATFORM 'F'
# define COLOR_WALL 0xAAFFAAFF
# define COLOR_EMPTY 0x00000000
# define COLOR_ALTERNATE 0x00FF00FF

typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	mlx_texture_t		*player_texture;
	mlx_image_t			*player_img;
	mlx_image_t			*background_img;
	mlx_texture_t		*collectible_textures[COLLECTIBLE_FRAMES];
	mlx_texture_t		*exit_texture;
	mlx_texture_t		*wall_texture;
	mlx_texture_t		*platform_textures[PLATFORM_FRAMES];
	mlx_image_t			*collectible[COLLECTIBLE_FRAMES];
	mlx_image_t			*exit_img;
	mlx_image_t			*wall_img;
	mlx_image_t			*platform_images[PLATFORM_FRAMES];
	int					player_x;
	int					player_y;
	int					old_player_x;
	int					old_player_y;
	int					moves;
	int					collectibles_collected;
	bool				game_over;
	int					current_player_frame;
	int					current_collectible_frame;
	int					current_platform_frame;
	char				**map;
	int					map_width;
	int					map_height;
	int					collectibles;
	int					move_count;
	int					screen_width;
	int					screen_height;
	mlx_texture_t		*trophy_texture;
	mlx_image_t			*trophy_img;
	bool				game_won;
	mlx_texture_t		*player_textures[4][3];
	mlx_image_t			*player_images[4][3];
	int					current_player_direction;
	uint32_t			background_color;
	mlx_instance_t		*player_instance;
	mlx_texture_t		*cover_texture;
	mlx_image_t			*cover_img;
	mlx_texture_t		*background_texture;
	int					exit_x;
	int					exit_y;
	bool				fullscreen;
	int					window_width;
	int					window_height;
	bool				is_resizing;
	int					windowed_width;
	int					windowed_height;
	int					width;
	int					height;
	int					px;
	int					py;
	int					ex;
	int					ey;
	int					dx;
	int					dy;
}	t_game;

typedef struct s_coords
{
	int	px;
	int	py;
	int	ex;
	int	ey;
	int	x;
	int	y;
}	t_coords;

typedef struct s_cell_data
{
	int		*player_count;
	int		*exit_count;
	t_game	*game;
}	t_cell_data;

typedef struct s_handle_cell_params
{
	t_game		*game;
	int			*player_count;
	int			*exit_count;
	int			x;
	int			y;
}	t_handle_cell_params;

mlx_image_t	*create_background_image(mlx_t *mlx, uint32_t color,
				int width, int height);
mlx_image_t	*load_cover_image(mlx_t *mlx, const char *filename);
uint32_t	retrieve_color(mlx_image_t *img, uint32_t x, uint32_t y);
void		error_exit(const char *message);
char		**read_map(char *filename);
void		locate_player(t_game *game);
bool		initialize_game(t_game *game);
void		clean_game(t_game *game);
void		move_player(t_game *game, int x, int y);
void		draw_map(void *param);
bool		validate_map(char **map, int rows, int cols, t_game *game);
void		close_hook(void *param);
void		display_trophy_and_close(t_game *game);
bool		is_wall_or_platform(t_game *game, int x, int y);
void		clear_screen(t_game *game);
void		redraw_area(t_game *game, int x, int y);
void		draw_background(t_game *game);
void		draw_tile(t_game *game, char tile_type, int x, int y);
void		erase_player(t_game *game, int x, int y);
void		collect_item(t_game *game, int x, int y);
void		draw_player(t_game *game);
void		clear_area(t_game *game, int x, int y);
void		cover_previous_position(t_game *game, int x, int y);
void		clear_player_area(t_game *game, int x, int y);
void		clear_entire_screen(t_game *game);
void		redraw_map(t_game *game);
bool		is_valid_move(t_game *game, int new_x, int new_y);
bool		is_within_bounds(t_game *game, int x, int y);
bool		is_exit_reachable(t_game *game, t_coords coords);
int			get_window_width(t_game *game);
int			get_window_height(t_game *game);
void		locate_exit(t_game *game);
bool		generate_map(t_game *game, int width, int height);
float		min_float(float a, float b);
void		handle_resize(int width, int height, t_game *game);
void		some_function(mlx_image_t *src_img);
void		window_resize_callback(int32_t width, int32_t height, void *param);
void		free_map(char **map, int rows);
void		draw_move_count(t_game *game);
void		render_text(t_game *game, const char *text, int x, int y);
void		key_hook(mlx_key_data_t keydata, void *param);
void		mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods,
				void *param);
void		cursor_hook(double xpos, double ypos, void *param);
void		init_mlx(t_game *game);
void		clean_collectibles_and_platforms(t_game *game);
void		clean_static_textures_and_images(t_game *game);
void		clean_texture_and_image(mlx_t *mlx, mlx_texture_t *texture,
				mlx_image_t *image);
void		clean_player_textures_and_images(t_game *game);
void		clean_textures(mlx_texture_t **textures, int count);
void		clean_images(mlx_t *mlx, mlx_image_t **images, int count);
bool		allocate_map_rows(t_game *game, int height);
bool		initialize_map_row(t_game *game, int y, int width);
bool		allocate_and_initialize_map(t_game *game, int width, int height);
void		place_collectibles(t_game *game, int width, int height);
bool		place_player(t_game *game, int width, int height);
bool		place_collectible(t_game *game, int cx, int cy);
void		place_collectibles(t_game *game, int width, int height);
bool		setup_map_environment(t_game *game);
bool		place_exit(t_game *game);
bool		set_exit_position(t_game *game);
void		place_walls(t_game *game, int width, int height);
bool		load_texture(char *path, mlx_texture_t **texture,
				mlx_image_t **image,
				t_game *game);
bool		load_player_textures(t_game *game);
bool		load_collectible_textures(t_game *game);
bool		load_platform_textures(t_game *game);
bool		load_cover_texture(t_game *game);
bool		load_textures(t_game *game);
bool		create_game_image(t_game *game);
void		validate_and_locate(t_game *game);
void		handle_args(int argc, char **argv, t_game *game);
void		set_map_dimensions(t_game *game);
bool		check_top_bottom_rows(t_game *game, int row);
bool		check_left_right_cols(t_game *game, int col);
bool		perform_dfs(t_game *game, t_coords player, t_coords exit);
void		update_game_image(int width, int height, t_game *game);
int			resize_and_display_background(int width, int height, t_game *game);
bool		load_new_background(t_game *game);
void		update_map_dimensions(int width, int height, t_game *game);
void		delete_existing_background(t_game *game);
void		check_exit_condition(t_game *game, int new_x, int new_y);
bool		dfs_mark_visited(t_game *game, t_coords pos);
int			get_line_count(int fd);
void		free_map(char **map, int rows);
char		**allocate_map(int rows, int cols);
void		fill_map_line(char **map, int line_index, int cols, int fd);
void		clear_entire_screen(t_game *game);
bool		load_background(t_game *game, const char *path);
bool		has_required_elements_helper(char **map, int rows,
				int cols, t_game *game);
bool		validate_map(char **map, int rows, int cols, t_game *game);
bool		is_surrounded_by_walls(char **map, int rows, int cols);
bool		is_rectangular_map(char **map, int rows);

#endif
