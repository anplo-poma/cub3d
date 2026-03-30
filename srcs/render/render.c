/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:46:56 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/30 23:28:01 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    calcu_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	if (ray->wall_dist < 0.0001)
        ray->wall_dist = 0.0001;
}


void    calcu_wall_height(t_ray *ray, int screen_height)
{
	ray->line_height = (int)(screen_height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + screen_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;//camp to avoid draw negative part
	ray->draw_end = ray->line_height / 2 + screen_height / 2;
	if (ray->draw_end >= screen_height)
		ray->draw_end = screen_height - 1;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}


void    draw_column(t_img *img, t_ray *ray, t_game *game, int x)
{
	t_texture 	*tex;
	t_texcalc	tc;
	int y;
	int tex_y;

	tex = get_texture(ray, game);
	calcu_tex(ray, tex, &tc, game->screen_height);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(img, x, y++, game->map.ceiling_color);
	while (y <= ray->draw_end)
	{
        tex_y = (int)tc.tex_pos % tex->height;
        tc.tex_pos += tc.step;
        put_pixel(img, x, y++,
            tex->pixels[tex_y * tex->width + tc.tex_x]);
    }
	while (y < game->screen_height)
		put_pixel(img, x, y++, game->map.floor_color);
}

void    render_frame(t_game *game)
{
	t_ray   ray;
	int     x;

	x = 0;
	while (x < game->screen_width)
	{
		ray.map_x = (int)game->player.player_x;
		ray.map_y = (int)game->player.player_y;
		find_wall(&ray, &game->player, game->map.matrix, x, game->screen_width);
		calcu_wall_dist(&ray);
		calcu_wall_height(&ray, game->screen_height);
		calcu_wall_x(&ray, &game->player);
		draw_column(&game->img, &ray, game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}