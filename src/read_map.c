/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analunga <analunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 05:45:12 by analunga          #+#    #+#             */
/*   Updated: 2024/09/08 00:10:22 by analunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static int	open_map_file(const char *filename)
{
	char	filepath[256];
	int		fd;

	ft_printf("Attempting to open file at path: ./Maps/%s\n", filename);
	ft_strlcpy(filepath, "./Maps/", sizeof(filepath));
	ft_strlcat(filepath, filename, sizeof(filepath));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening map file: %s\n", filepath);
		error_exit("Error opening map file");
	}
	return (fd);
}

static int	read_map_dimensions(int fd, int *cols)
{
	char	*first_line;
	int		line_count;

	line_count = get_line_count(fd);
	if (line_count == 0)
	{
		close(fd);
		error_exit("Error: Empty map file");
	}
	lseek(fd, 0, SEEK_SET);
	first_line = get_next_line(fd);
	if (!first_line)
	{
		close(fd);
		error_exit("Error reading first line of map file");
	}
	*cols = ft_strlen(first_line) - 1;
	free(first_line);
	return (line_count);
}

static void	load_map_lines(char **map, int line_count, int cols, int fd)
{
	int	i;

	lseek(fd, 0, SEEK_SET);
	i = 0;
	while (i < line_count)
	{
		fill_map_line(map, i, cols, fd);
		i++;
	}
	map[line_count] = NULL;
}

char	**read_map(char *filename)
{
	int		fd;
	char	**map;
	int		line_count;
	int		cols;

	fd = open_map_file(filename);
	line_count = read_map_dimensions(fd, &cols);
	map = allocate_map(line_count, cols);
	if (!map)
	{
		close(fd);
		error_exit("Error allocating map memory");
	}
	load_map_lines(map, line_count, cols, fd);
	close(fd);
	return (map);
}
