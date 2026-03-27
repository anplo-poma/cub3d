#include "cub3d.h"

// 计算射线偏移量
// 此处x为射线相对屏幕的位置，如屏幕为600px，x可以为0-599，0为屏幕最左，599为最右
void    calcu_camera_x(t_ray *ray, int x, int screen_width)
{
    if (!ray || screen_width == 0)
        return ;
    ray->camera_x = 2.0 * x /  (double)screen_width - 1.0;
}

// 计算射线的方向，dir_x, dir_y
void    calcu_ray_dir(t_ray *ray, t_player *player)
{
    if (!ray)
        return ;
    ray->dir_x = player->player_dir_x + player->plane_x * ray->camera_x;
    ray->dir_y = player->player_dir_y + player->plane_y * ray->camera_x;
}

// 计算射线在X方向的投影走1，沿射线会走多远, deltadist_x deltadist_y 
void    calcu_deltadist(t_ray *ray) 
{
    if (!ray)
        return ;
    ray->deltadist_x = fabs(1 / ray->dir_x);
    ray->deltadist_y = fabs(1 / ray->dir_y);
}

// 从玩家位置出发，沿射线走，要走多远才会碰到相邻的格子的边界
// 此处未包含到struct的参数：player_x/player_y（玩家当前位置）
void    calcu_sidedist(t_ray *ray, t_player *player) 
{
    if (!ray)
        return ;
    if (ray->dir_x > 0)
        ray->sidedist_x = (ray->map_x + 1.0 - player->player_x) * ray->deltadist_x;
    else
        ray->sidedist_x = (player->player_x - ray->map_x) * ray->deltadist_x;
    if (ray->dir_y > 0)
        ray->sidedist_y = (ray->map_y + 1.0 - player->player_y) * ray->deltadist_y;
    else
        ray->sidedist_y = (player->player_y - ray->map_y) * ray->deltadist_y;
}

// 根据行进方向，初始化step的值
void    init_step(t_ray *ray)
{
    if (ray->dir_x < 0)
        ray->step_x = -1;
    else
        ray->step_x = 1;
    if (ray->dir_y < 0)
        ray->step_y = -1;
    else
        ray->step_y = 1;
}

//dda部分，以地图内的格子为界，判断当前格子是否为墙壁, side
void    dda_hit_wall(t_ray *ray, int hit, char **map)
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
        if(map[ray->map_y][ray->map_x]== '1')
            hit = 1;
    }
}

void    find_wall(t_ray *ray, t_player *player, char **map, int x, int screen_width)
{
    calcu_camera_x(ray, x, screen_width);
    calcu_ray_dir(ray, player);
    calcu_deltadist(ray);
    init_step(ray);
    calcu_sidedist(ray, player);
    dda_hit_wall(ray, 0, map);
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