#ifndef cub3d_h
# define cub3d_h

# include <math.h>
# include <stdio.h>

typedef struct s_ray
{
    double    camera_x;// 这条射线对应屏幕哪个位置（-1左 ~ 0中 ~ 1右）(cal)
	
    double    dir_x;  // 射线方向 X(cal)
    double    dir_y;

    int        map_x;//玩家所在格子 then 撞到的那个墙格子的 X 坐标
    int        map_y;
    int        step_x;
    int        step_y;
    double    sidedist_x;
    double    sidedist_y;

    double    deltadist_x;// 走到下一条X边界需要多远 then 最后一次跳完之后，X方向累积的距离
    double    deltadist_y;
    double    wall_dist;
    double    wall_x;
    int        side; // 撞到的是哪个方向的面
    int        line_height;
    int        draw_start;
    int        draw_end;
}    t_ray;

typedef struct s_player
{
    double player_dir_x; // 从玩家视线出发的向量
    double player_dir_y;
    double plane_x; // 玩家视线前方的宽度，与玩家视线出发的向量垂直
    double plane_y;
    double player_x; // 玩家坐标
    double player_y;
}   t_player;

#endif
