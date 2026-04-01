/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannahhao <hannahhao@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:31:54 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/01 20:26:03 by hannahhao        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map_to_str(t_mapdata *mapdata, char* line)
{
	char*	tmp;
	tmp = mapdata->raw_str;
    mapdata->raw_str = ft_strjoin(mapdata->raw_str, line);
    free(tmp);
}


void build_matrix(t_mapdata *mapdata)
{
    int     i;
    int     max_len;

    mapdata->raw_lines = ft_split(mapdata->raw_str, '\n');
    //free(mapdata->raw_str); could give it to free all later
    i = 0;
    max_len = 0;
    while (mapdata->raw_lines[i])
    {
        if ((int)ft_strlen(mapdata->raw_lines[i]) > max_len)
            max_len = ft_strlen(mapdata->raw_lines[i]);
        i++;
    }
    mapdata->rows = i;
    mapdata->cols = max_len;
}

void	pad_matrix_rows(t_game *game)
{
	t_mapdata	*map;
	int		i;
	int		j;

	map = &game->map;
	map->matrix = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->matrix)
		ft_error(game, "malloc failed");
	i = 0;
	while (i < map->rows)
	{
		map->matrix[i] = malloc(map->cols + 1);
		if (!map->matrix[i])
			ft_error(game, "malloc failed");
		j = 0;
		while (j < map->cols)
			map->matrix[i][j++] = ' ';
		map->matrix[i][map->cols] = '\0';
		ft_cub_strlcpy(map->matrix[i], map->raw_lines[i],
			ft_strlen(map->raw_lines[i]) + 1);
		i++;
	}
	map->matrix[map->rows] = NULL;
}
