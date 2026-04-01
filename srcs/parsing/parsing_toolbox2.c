/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_toolbox2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannahhao <hannahhao@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:52:06 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/01 20:13:15 by hannahhao        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n' || line[i] == '\r'))
		i++;
	return (line[i] == '\0');
}

int	is_map_line(char *line)
{
	char	*p;

	p = line;
	while (*p == ' ' || *p == '\t')
		p++;
	if ((*p == 'N' && *(p+1) == 'O') ||
		(*p == 'S' && *(p+1) == 'O') ||
		(*p == 'W' && *(p+1) == 'E') ||
		(*p == 'E' && *(p+1) == 'A') ||
		(*p == 'F' && *(p+1) == ' ') ||
		(*p == 'C' && *(p+1) == ' '))
		return (0);
	return (*p == '0' || *p == '1' || *p == 'N' || *p == 'S'
		|| *p == 'E' || *p == 'W' || *p == ' ');
}

int	is_valid_pos(t_mapdata *map, int y, int x)
{
	int	len;

	if (y < 0 || y >= map->rows)
		return (0);
	len = ft_strlen(map->matrix[y]);
	if (x < 0 || x >= len)
		return (0);
	if (map->matrix[y][x] == ' ')
		return (0);
	return (1);
}
