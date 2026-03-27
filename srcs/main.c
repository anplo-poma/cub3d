/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:05:18 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/27 18:53:09 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int	main(int ac, char** av)
{
	t_data	cub;
	
	if (ac != 2)
		return ("error msg");
	cub.mlx = mlx_init(&cub);
	check_map(av[1], cub);
	cub.win = mlx_new_window();
	init_all(cub);
	mlx_hook();
	mlx_loop_hook(render_map());
	mlx_loop();
}
*/
/*
int	main(int ac, char** av)
{
	if (ac != 2)
		return ("error msg");
	open
}
*/


/*
顺序：
parse + validate    → 确认文件完全合法
    ↓
mlx_init()          → 创建 mlx
    ↓
load textures        → mlx_xpm_file_to_image
    ↓
game loop


*/
