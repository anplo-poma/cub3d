/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:31:54 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/02 23:23:19 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_valid_char(t_mapdata *map)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while(map->matrix[y][x])
		{
			c = map->matrix[y][x];
			if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'E' && c != 'S' && c != 'W')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_player_num(t_mapdata *map)
{
	int	y;
	int	x;
	int	c;
	int player_count;

	y = 0;
	player_count = 0;
	while (map->matrix[y])
	{
		x = 0;
		while(map->matrix[y][x])
		{
			c = map->matrix[y][x];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				player_count++;
				if (player_count > 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_neighbors(t_mapdata *map, int y, int x)
{
	if (!is_valid_pos(map, y - 1, x))
		return (0);
	if (!is_valid_pos(map, y + 1, x))
		return (0);
	if (!is_valid_pos(map, y, x - 1))
		return (0);
	if (!is_valid_pos(map, y, x + 1))
		return (0);
	return (1);
}

static int	check_closed(t_mapdata *map)
{
	int	y;
	int	x;
	int	len;
	char	c;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		len = ft_strlen(map->matrix[y]);
		while (x < len)
		{
			c = map->matrix[y][x];
			if (c == '0' || c == 'N' || c == 'S'
				|| c == 'E' || c == 'W')
			{
				if (!check_neighbors(map, y, x))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static void check_required_content(t_game *game)
{
    t_mapdata *map;

    map = &game->map;
    if (!map->no_texture || !map->so_texture
        || !map->we_texture || !map->ea_texture)
        ft_error(game, "missing texture identifier (NO/SO/WE/EA)");
    if (map->floor_color == -1 || map->ceiling_color == -1)
        ft_error(game, "missing color identifier (F/C)");
}

void	validate_map(t_game *game)
{
	t_mapdata	*map;

	map = &game->map;
	 check_required_content(game); 
	if (!check_valid_char(map))
		ft_error(game, "Map contains invalid characters.");
	if (!check_player_num(map))
		ft_error(game, "Map must contain exactly one player.");
	if (!check_closed(map))
		ft_error(game, "Map must be closed.");
}
