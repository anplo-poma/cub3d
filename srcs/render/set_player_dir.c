/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:30:49 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/07 22:54:21 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_dir_vec(t_player *p, double x, double y)
{
	p->player_dir_x = x;
	p->player_dir_y = y;
}

static void	set_plane_vec(t_player *p, double x, double y)
{
	p->plane_x = x;
	p->plane_y = y;
}

static void	apply_dir(t_player *player, char dir)
{
	if (dir == 'N')
		set_dir_vec(player, 0, -1);
	else if (dir == 'S')
		set_dir_vec(player, 0, 1);
	else if (dir == 'E')
		set_dir_vec(player, 1, 0);
	else if (dir == 'W')
		set_dir_vec(player, -1, 0);
}

static void	apply_plane(t_player *player, char dir)
{
	if (dir == 'N')
		set_plane_vec(player, 0.66, 0);
	else if (dir == 'S')
		set_plane_vec(player, -0.66, 0);
	else if (dir == 'E')
		set_plane_vec(player, 0, 0.66);
	else if (dir == 'W')
		set_plane_vec(player, 0, -0.66);
}

void	set_player_dir(t_player *player, char dir)
{
	apply_dir(player, dir);
	apply_plane(player, dir);
}
