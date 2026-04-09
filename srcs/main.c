/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:05:18 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/09 10:40:12 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game, "mlx_init failed");
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3D");
	if (!game->win)
		ft_error(game, "mlx_new_window failed");
	game->img.img_ptr = mlx_new_image(game->mlx,
			game->screen_width, game->screen_height);
	if (!game->img.img_ptr)
		ft_error(game, "mlx_new_image failed");
	game->img.addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.line_len, &game->img.endian);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./cub3D <map.cub>\n");
		return (1);
	}
	init_game(&game);
	parse_cub(av[1], &game, &game.map);
	find_player_location(&game);
	init_mlx(&game);
	load_textures(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}

// load_textures(&game);not init in init_game because not created yet