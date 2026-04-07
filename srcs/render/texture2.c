/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:28:19 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/07 22:49:09 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcu_wall_x(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_x = player->player_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->player_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
