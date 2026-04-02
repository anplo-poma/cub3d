/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:26:10 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/02 23:23:31 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* srcs/init_player_spawn.c */
#include "../include/cub3d.h"

static void	set_dir(t_player *player,
			double dir_x, double dir_y,
			double plane_x, double plane_y)
{
	player->player_dir_x = dir_x;
	player->player_dir_y = dir_y;
	player->plane_x = plane_x;
	player->plane_y = plane_y;
}

void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
		set_dir(player, 0, -1, 0.66, 0);
	else if (dir == 'S')
		set_dir(player, 0, 1, -0.66, 0);
	else if (dir == 'E')
		set_dir(player, 1, 0, 0, 0.66);
	else if (dir == 'W')
		set_dir(player, -1, 0, 0, -0.66);
}

void	find_player_location(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (game->map.matrix[y])
	{
		x = 0;
		while (game->map.matrix[y][x])
		{
			c = game->map.matrix[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player.player_x = x + 0.5;//set player into middle
				game->player.player_y = y + 0.5;
				set_player_dir(&game->player, c);
				game->map.matrix[y][x] = '0'; // replace player position to enpty
				return ;
			}
			x++;
		}
		y++;
	}
	ft_error(game, "No player spawn found in map");
}