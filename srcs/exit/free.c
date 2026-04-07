/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:10:07 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/02 22:54:42 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static void	ft_free_mapdata(t_mapdata *map)
{
	if (map->no_texture)
	{
		free(map->no_texture);
		map->no_texture = NULL;
	}
	if (map->so_texture)
	{
		free(map->so_texture);
		map->so_texture = NULL;
	}
	if (map->we_texture)
	{
		free(map->we_texture);
		map->we_texture = NULL;
	}
	if (map->ea_texture)
	{
		free(map->ea_texture);
		map->ea_texture = NULL;
	}
	if (map->raw_str)
	{
		free(map->raw_str);
		map->raw_str = NULL;
	}
	if (map->raw_lines)
	{
		ft_free_matrix(map->raw_lines);
		map->raw_lines = NULL;
	}
	if (map->matrix)
	{
		ft_free_matrix(map->matrix);
		map->matrix = NULL;
	}
}

static void	ft_free_textures(t_game *game)
{
	if (game->tex_no.pixels)
	{
		free(game->tex_no.pixels);
		game->tex_no.pixels = NULL;
	}
	if (game->tex_so.pixels)
	{
		free(game->tex_so.pixels);
		game->tex_so.pixels = NULL;
	}
	if (game->tex_we.pixels)
	{
		free(game->tex_we.pixels);
		game->tex_we.pixels = NULL;
	}
	if (game->tex_ea.pixels)
	{
		free(game->tex_ea.pixels);
		game->tex_ea.pixels = NULL;
	}
}

/*
img → window → display → free(mlx itself)
*/
static void	ft_free_mlx(t_game *game)
{
	if (game->mlx && game->img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->img.img_ptr);
		game->img.img_ptr = NULL;
	}
	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	get_next_line(-1);
	if (game->fd > 0)
		close(game->fd);
	ft_free_mapdata(&game->map);
	ft_free_textures(game);
	ft_free_mlx(game);
}
