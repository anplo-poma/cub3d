/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:19:38 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/02 21:22:50 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_rgb(t_game *game, char *str)
{
	char	**parts;
	int		rgb[3];
	int		i;

	parts = ft_split(str, ',');
	if (!parts)
		ft_error(game, "invalid color");
	i = 0;
	while (parts[i])
		i++;
	if (i != 3)
	{
		ft_free_matrix(parts);
		ft_error(game, "invalid color: need 3 values for R,G and B");
	}
	i = 0;
	while (i < 3)
	{
		if (!is_all_digits(parts[i]))
		{
			ft_free_matrix(parts);
			ft_error(game, "invalid color: not a number");
		}
		rgb[i] = ft_atoi(parts[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_free_matrix(parts);
			ft_error(game, "invalid color: out of range 0-255");
		}
		i++;
	}
	ft_free_matrix(parts);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	read_six_surface_to_struct(t_game *game, char *line)
{
	t_mapdata	*map;

	map = &game->map;
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->no_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		map->so_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		map->we_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		map->ea_texture = ft_strdup(trim_newline(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "F ", 2) == 0)
		map->floor_color = parse_rgb(game,
				trim_newline(skip_spaces(line + 2)));
	else if (ft_strncmp(line, "C ", 2) == 0)
		map->ceiling_color = parse_rgb(game,
				trim_newline(skip_spaces(line + 2)));
	else
		ft_error(game, "unknown identifier");
}

static void	process_line(t_game *game, char *line, int *map_start, int *map_end)
{
	if (*map_end)
	{
		free(line);
		ft_error(game, "empty line in map");
	}
	if (!*map_start && is_map_line(line))
		*map_start = 1;
	if (*map_start)
		read_map_to_str(&game->map, line);
	else
		read_six_surface_to_struct(game, line);
	free(line);
}

static void	each_line_check(t_game *game, int fd)
{
	char	*line;
	int		map_start;
	int		map_end;

	map_start = 0;
	map_end = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_empty_line(line))
		{
			if (map_start)
				map_end = 1;
			free(line);
			continue ;
		}
		process_line(game, line, &map_start, &map_end);
	}
}

void	read_cub_file(const char *filename, t_game *game)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(game, "cannot open file");
	each_line_check(game, fd);
	close(fd);
}

int	check_map_extension(const char *filename)
{
	const char	*ext;

	if (!filename)
		return (0);
	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".cub", 5))
		return (0);
	if (ext == filename || *(ext - 1) == '/')
		return (0);
	return (1);
}

void	parse_cub(const char *filename, t_game *game)
{
	if (!check_map_extension(filename))
		ft_error(game, "invalid file extension");
	read_cub_file(filename, game);
	build_matrix(&game->map);
	pad_matrix_rows(game);
	validate_map(game);
}