/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:26:10 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/07 22:52:32 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
				game->player.player_x = x + 0.5;
				game->player.player_y = y + 0.5;
				set_player_dir(&game->player, c);
				game->map.matrix[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	ft_error(game, "No player spawn found in map");
}

/*
game->player.player_x = x + 0.5;//set player into middle
				game->player.player_y = y + 0.5;
				set_player_dir(&game->player, c);
				game->map.matrix[y][x] = '0'; // replace player position to enpty
*/