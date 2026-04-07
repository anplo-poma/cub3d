/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:47:10 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/07 22:59:16 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_mapdata(t_mapdata *map)
{
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->rows = 0;
	map->cols = 0;
	map->raw_str = ft_strdup("");
	map->raw_lines = NULL;
	map->matrix = NULL;
}
//	map->raw_str = ft_strdup("");   // new version ori NULL

static void	init_player(t_player *player)
{
	player->player_x = 0;
	player->player_y = 0;
	player->player_dir_x = -1;
	player->player_dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	init_img(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

static void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

static void	init_textures(t_game *game)
{
	game->tex_no.pixels = NULL;
	game->tex_no.width = 0;
	game->tex_no.height = 0;
	game->tex_so.pixels = NULL;
	game->tex_so.width = 0;
	game->tex_so.height = 0;
	game->tex_we.pixels = NULL;
	game->tex_we.width = 0;
	game->tex_we.height = 0;
	game->tex_ea.pixels = NULL;
	game->tex_ea.width = 0;
	game->tex_ea.height = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->screen_width = SCREEN_W;
	game->screen_height = SCREEN_H;
	game->rotate = 0;
	game->move_x = 0;
	game->move_y = 0;
	game->fd = -1;
	init_mapdata(&game->map);
	init_player(&game->player);
	init_img(&game->img);
	init_ray(&game->ray);
	init_textures(game);
}
