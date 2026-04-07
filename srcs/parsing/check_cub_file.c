/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:19:38 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/07 22:55:59 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_empty_line(line))
		{
			if (map_start)
				map_end = 1;
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		process_line(game, line, &map_start, &map_end);
		line = get_next_line(fd);
	}
}

void	read_cub_file(const char *filename, t_game *game)
{
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		ft_error(game, "cannot open file");
	each_line_check(game, game->fd);
	close(game->fd);
	game->fd = -1;
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

void	parse_cub(const char *filename, t_game *game, t_mapdata *map)
{
	if (!check_map_extension(filename))
		ft_error(game, "invalid file extension");
	read_cub_file(filename, game);
	if (map->floor_color == -1 || map->ceiling_color == -1)
		ft_error(game, "missing F or C color");
	build_matrix(&game->map);
	pad_matrix_rows(game);
	validate_map(game);
}
