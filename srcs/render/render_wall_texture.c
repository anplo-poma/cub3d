/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:22:18 by xuewang           #+#    #+#             */
/*   Updated: 2026/03/28 20:58:07 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
t_texture *get_texture(t_ray *ray, t_game *game)
{
    if (ray->side == 1 && ray->dir_y < 0) 
        return (&game->tex_north);
    if (ray->side == 1 && ray->dir_y > 0) 
        return (&game->tex_south);
    if (ray->side == 0 && ray->dir_x < 0) 
        return (&game->tex_west);
    return (&game->tex_east);
}
    */