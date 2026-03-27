/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:17:04 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/27 21:16:59 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//#include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"


typedef struct s_data{
	
}t_data;

typedef struct s_img{
	
}t_img;

typedef	struct s_mapdata{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	int		rows;
	int		cols;
	char	*raw_str;
	char	**raw_lines;
	char	**matrix;
}t_mapdata;




//LINNA PART//
/***************************************************************** */
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

/******************************************************************** */
//LINNA PART END//




typedef struct s_cub
{
	
}t_cub;


#endif