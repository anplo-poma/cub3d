/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:31:54 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/27 21:28:51 by xueyan_wang      ###   ########.fr       */
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

void	pad_matrix_rows(t_mapdata *mapdata)
{
	int		i;
	int		j;

	mapdata->matrix = malloc(sizeof(char *) * (mapdata->rows + 1));
	if (!mapdata->matrix)
		ft_error("malloc failed");
	i = 0;
	while (i < mapdata->rows)
	{
		mapdata->matrix[i] = malloc(mapdata->cols + 1);
		if (!mapdata->matrix[i])
			ft_error("malloc failed");
		j = 0;
		while (j < mapdata->cols)
			mapdata->matrix[i][j++] = ' ';
		mapdata->matrix[i][mapdata->cols] = '\0';
		ft_cub_strlcpy(mapdata->matrix[i], mapdata->raw_lines[i],
			ft_strlen(mapdata->raw_lines[i]) + 1);
		i++;
	}
	mapdata->matrix[mapdata->rows] = NULL;
}
