/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_file_six_sur.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 21:36:55 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/09 12:15:15 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_rgb(char *str)
{
	char	**parts;
	char	*trimmed;
	int		rgb[3];
	int		i;

	parts = ft_split(str, ',');
	if (!parts)
		return (-1);
	i = 0;
	while (parts[i])
		i++;
	if (i != 3)
		return (ft_free_matrix(parts), -1);
	i = 0;
	while (i < 3)
	{
		trimmed = skip_spaces(parts[i]);
		trimnl(trimmed);
		rgb[i] = ft_atoi(parts[i]);
		if (!is_all_digits(parts[i]) || rgb[i] < 0 || rgb[i] > 255)
			return (ft_free_matrix(parts), -1);
		i++;
	}
	ft_free_matrix(parts);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

//set_texture
void	set_tex(t_game *game, char *line, char **field, char *value)
{
	if (*field)
	{
		free(line);
		ft_error(game, "duplicate texture identifier");
	}
	*field = ft_strdup(value);
	if (!*field)
	{
		free(line);
		ft_error(game, "malloc failed in set_texture");
	}
}

//set_color
void	set_co(t_game *game, char *line, int *field, char *value)
{
	int	color;

	color = parse_rgb(value);
	if (color < 0)
	{
		free(line);
		ft_error(game, "invalid color value");
	}
	if (*field != -1)
	{
		free(line);
		ft_error(game, "duplicate color identifier");
	}
	*field = color;
}

static void	check_missing_space(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
	{
		free(line);
		ft_error(game, "missing space after texture identifier");
	}
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		free(line);
		ft_error(game, "missing space after color identifier");
	}
	free(line);
	ft_error(game, "unknown identifier");
}

void	read_six_surface_to_struct(t_game *game, char *line)
{
	t_mapdata	*map;

	map = &game->map;
	if (ft_strncmp(line, "NO ", 3) == 0)
		set_tex(game, line, &map->no_texture, trimnl(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		set_tex(game, line, &map->so_texture, trimnl(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_tex(game, line, &map->we_texture, trimnl(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_tex(game, line, &map->ea_texture, trimnl(skip_spaces(line + 3)));
	else if (ft_strncmp(line, "F ", 2) == 0)
		set_co(game, line, &map->floor_color, trimnl(skip_spaces(line + 2)));
	else if (ft_strncmp(line, "C ", 2) == 0)
		set_co(game, line, &map->ceiling_color, trimnl(skip_spaces(line + 2)));
	else
		check_missing_space(game, line);
}
