/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:04:32 by lhao              #+#    #+#             */
/*   Updated: 2026/04/07 22:01:22 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//dda部分，以地图内的格子为界，判断当前格子是否为墙壁, side
void	dda_hit_wall(t_ray *ray, int hit, char **map)
{
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_y < 0)
			hit = 1;
		else if (map[ray->map_y] && map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	find_wall(t_ray *ray, t_game *game, int x)
{
	calcu_camera_x(ray, x, game->screen_width);
	calcu_ray_dir(ray, &game->player);
	calcu_deltadist(ray);
	init_step(ray);
	calcu_sidedist(ray, &game->player);
	dda_hit_wall(ray, 0, game->map.matrix);
}

// for test
// int main(void)
// {
//     char *map[] = {
//         "11111",
//         "10001",
//         "10001",
//         "10001",
//         "11111",
//         NULL
//     };

//     t_player player;
//     player.player_x = 2.5;
//     player.player_y = 2.5;

//     player.player_dir_x = 1.0;  // 玩家朝右
//     player.player_dir_y = 0.0;

//     player.plane_x = 0.0;   // camera plane
//     player.plane_y = 0.66;

//     int screen_width = 640;
//     int test_positions[] = {0, 160, 320, 480, 639};  // 左、左中、中、右中、右
//     int i;

//     for (i = 0; i < 5; i++)
//     {
//         int x = test_positions[i];
//         t_ray ray;
//         ray.map_x = (int)player.player_x;
//         ray.map_y = (int)player.player_y;

//         find_wall(&ray, &player, map, x, screen_width);

//         printf("\n=== Ray test x=%d ===\n", x);
//         printf("camera_x = %g\n", ray.camera_x);
//         printf("dir = (%g, %g)\n", ray.dir_x, ray.dir_y);
//         printf("delta = (%g, %g)\n", ray.deltadist_x, ray.deltadist_y);
//         printf("sideDist = (%g, %g)\n", ray.sidedist_x, ray.sidedist_y);
//         printf("hit map = (%d, %d)\n", ray.map_x, ray.map_y);
//         printf("side = %d\n", ray.side);
//     }

//     return 0;
// }