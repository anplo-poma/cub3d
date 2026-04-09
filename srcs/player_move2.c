/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:42:41 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/09 10:43:59 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall(t_game *game, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || my < 0 || my >= game->map.rows || mx >= game->map.cols)
		return (1);
	if (!game->map.matrix[my])
		return (1);
	return (game->map.matrix[my][mx] == '1');
}
//mx < 0 my < 0 ...: if we reach outside the baudary we all see it as the wall

void	rotate_player(t_game *game, double angle)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &game->player;
	old_dir_x = p->player_dir_x;
	p->player_dir_x = old_dir_x * cos(angle) - p->player_dir_y * sin(angle);
	p->player_dir_y = old_dir_x * sin(angle) + p->player_dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = old_plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

//rotate = angle puls angle = cos/sin calculation。
/*
(x, y) = (cos α, sin α)
turn angle:
(cos(α+θ), sin(α+θ))
=
cos(α+θ) = cos α · cos θ  -  sin α · sin θ
sin(α+θ) = cos α · sin θ  +  sin α · cos θ

cos α = x，sin α = y

new_x = x · cosθ - y · sinθ
new_y = x · sinθ + y · cosθ

*/