/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:32:28 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/07 22:51:24 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//special free for mlx 
//becuase here the img_ptr has not in game struct yet need to free
static void	copy_pixels(t_texture *tex, char *addr, int bpp, int line_len)
{
	int	x;
	int	y;

	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			tex->pixels[y * tex->width + x]
				= *(int *)(addr + y * line_len + x * (bpp / 8));
			x++;
		}
		y++;
	}
}

static void	load_one_texture(t_game *game, t_texture *tex, char *path)
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!img_ptr)
		ft_error(game, "texture loading failed");
	addr = mlx_get_data_addr(img_ptr, &bpp, &line_len, &endian);
	tex->pixels = malloc(sizeof(int) * tex->width * tex->height);
	if (!tex->pixels)
	{
		mlx_destroy_image(game->mlx, img_ptr);
		ft_error(game, "malloc failed in load_one_texture");
	}
	copy_pixels(tex, addr, bpp, line_len);
	mlx_destroy_image(game->mlx, img_ptr);
}

void	load_textures(t_game *game)
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

void	calcu_tex(t_ray *ray, t_texture *tex,
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
