/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:36:05 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/09 10:37:54 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_mapdata(t_mapdata *map)
{
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->rows = 0;
	map->cols = 0;
	map->raw_str = ft_strdup("");
	map->raw_lines = NULL;
	map->matrix = NULL;
}
//	map->raw_str = ft_strdup("");   // new version ori NULL