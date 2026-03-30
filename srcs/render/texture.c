/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:32:28 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/30 22:50:15 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void load_one_texture(t_game *game, t_texture *tex, char* path)
{
	void    *img_ptr;
	char    *addr;
	int     bpp;
	int     line_len;
	int     endian;

	img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!img_ptr)
	{
		ft_printf("Error: failed to load: '%s'\n", path);
		ft_error("texture load failed\n");
	}
	addr = mlx_get_data_addr(img_ptr, &bpp, &line_len, &endian);
	tex->pixels = malloc(sizeof(int)* tex->width * tex->height);
	if (!tex->pixels)
		ft_error("Malloc failed in load_one_texture");
	int y = 0;
	while (y < tex->height)
	{
		int x = 0;
		while (x < tex->width)
		{
			tex->pixels[y * tex->width + x] =
				*(int *)(addr + y * line_len + x * (bpp / 8));
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img_ptr);
}

void    load_textures(t_game *game)
{
	load_one_texture(game, &game->tex_no, game->map.no_texture);
	load_one_texture(game, &game->tex_so, game->map.so_texture);
	load_one_texture(game, &game->tex_we, game->map.we_texture);
	load_one_texture(game, &game->tex_ea, game->map.ea_texture);
}

t_texture	*get_texture(t_ray *ray, t_game *game)
{
	if (ray->side == 1 && ray->dir_y < 0)
		return (&game->tex_no);
	if (ray->side == 1 && ray->dir_y > 0)
		return (&game->tex_so);
	if (ray->side == 0 && ray->dir_x < 0)
		return (&game->tex_we);
	return (&game->tex_ea);
}

void calcu_tex(t_ray *ray, t_texture *tex,
                      t_texcalc *tc, int screen_height)
{
	tc->tex_x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->dir_x < 0)
		tc->tex_x = tex->width - tc->tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tc->tex_x = tex->width - tc->tex_x - 1;
	tc->step = (double)tex->height / ray->line_height;
	tc->tex_pos = (ray->draw_start - screen_height / 2
					+ ray->line_height / 2) * tc->step;
}

/*

static void calcu_tex(t_ray *ray, t_texture *tex,
                      t_texcalc *tc, int screen_height)
{
	//ray on which column ->project with column of texture
	tc->tex_x = (int)(ray->wall_x * tex->width);
	//different ray direction
	if (ray->side == 0 && ray->dir_x < 0)
		tc->tex_x = tex->width - tc->tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tc->tex_x = tex->width - tc->tex_x - 1;
	//原处纹理如何压缩以展现远处信息更少
	tc->step = (double)tex->height / ray->line_height;
	//wall middle match texture middle
	tc->tex_pos = (ray->draw_start - screen_height / 2
					+ ray->line_height / 2) * tc->step;
}

*/

void	calcu_wall_x(t_ray *ray, t_player *player)
{
    if (ray->side == 0)
        ray->wall_x = player->player_y + ray->wall_dist * ray->dir_y;
    else
        ray->wall_x = player->player_x + ray->wall_dist * ray->dir_x;
    ray->wall_x -= floor(ray->wall_x);
}