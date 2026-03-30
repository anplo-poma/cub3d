/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:17:04 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/30 23:01:27 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_ESC    65307

# define SCREEN_W 	1280
# define SCREEN_H 	720

#define MOVESPEED 0.05
# define MARGIN 0.2


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

typedef struct s_img
{
    void    *img_ptr;
    char    *addr;
    int     bpp;//normally 32
    int     line_len;//bit per line
    int     endian;//bit order
}t_img;

typedef struct s_texture
{
    int     *pixels;   // pixel arrey
    int     width;
    int     height;
} t_texture;

//just for middle step calculation
typedef struct s_texcalc
{
    int     tex_x;
    double  step;
    double  tex_pos;
}   t_texcalc;

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

typedef struct s_game
{
	int 		move_x;  // A=-1, D=1, not move=0
	int 		move_y;  // W=1, S=-1, not move=0
	void		*mlx;
	void		*win;
	int			screen_height;
	int			screen_width;
    
    t_texture   tex_no;
    t_texture   tex_so;
    t_texture   tex_we;
    t_texture   tex_ea;

	t_mapdata	map;
	t_ray		ray;
	t_player	player;
	t_img		img;
    t_texture texture;
} t_game;

/* ============================================================ */
/*  srcs/init.c                                                 */
/* ============================================================ */
void	init_game(t_game *game);

/* ============================================================ */
/*  srcs/main.c  (init_mlx 是 static，不需要声明)               */
/* ============================================================ */

/* ============================================================ */
/*  srcs/hook.c                                                 */
/* ============================================================ */
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_window(t_game *game);
void	setup_hooks(t_game *game);

/* ============================================================ */
/*  srcs/find_wall.c                                            */
/* ============================================================ */
void	calcu_camera_x(t_ray *ray, int x, int screen_width);
void	calcu_ray_dir(t_ray *ray, t_player *player);
void	calcu_deltadist(t_ray *ray);
void	calcu_sidedist(t_ray *ray, t_player *player);
void	init_step(t_ray *ray);
void	dda_hit_wall(t_ray *ray, int hit, char **map);
void	find_wall(t_ray *ray, t_player *player, char **map,
			int x, int screen_width);

/* ============================================================ */
/*  srcs/render.c                                               */
/* ============================================================ */
void	calcu_wall_dist(t_ray *ray);
void	calcu_wall_height(t_ray *ray, int screen_height);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_column(t_img *img, t_ray *ray, t_game *game, int x);
void	render_frame(t_game *game);

/* ============================================================ */
/*  srcs/render/texture.c                                       */
/* ============================================================ */
void    load_textures(t_game *game);
void    calcu_wall_x(t_ray *ray, t_player *player);
void    calcu_tex(t_ray *ray, t_texture *tex,
                      t_texcalc *tc, int screen_height);
t_texture   *get_texture(t_ray *ray, t_game *game);
/* ============================================================ */
/*  srcs/player_move.c                                          */
/* ============================================================ */
void	move_player(t_game *game);

/* ============================================================ */
/*  srcs/find_player.c                                          */
/* ============================================================ */
void	set_player_dir(t_player *player, char dir);
void	find_player_location(t_game *game);

/* ============================================================ */
/*  srcs/exit/error.c                                           */
/* ============================================================ */
int		ft_error(const char *errmsg);

/* ============================================================ */
/*  srcs/exit/free.c                                            */
/* ============================================================ */
void	ft_free_all(void);
void	ft_free_matrix(char **matrix);

/* ============================================================ */
/*  srcs/parsing/check_cub_file.c                               */
/* ============================================================ */
void	read_six_surface_to_struct(t_mapdata *mapdata, char *line);
void	read_cub_file(const char *filename, t_mapdata *mapdata);
int		check_map_extension(const char *filename);
void	parse_cub(const char *filename, t_mapdata *mapdata);
//void	debug_matrix(t_mapdata *mapdata);
/* ============================================================ */
/*  srcs/parsing/check_map.c                                    */
/* ============================================================ */
void	read_map_to_str(t_mapdata *mapdata, char *line);
void	build_matrix(t_mapdata *mapdata);
void	pad_matrix_rows(t_mapdata *mapdata);
void	validate_map(t_mapdata *mapdata);       //later

/* ============================================================ */
/*  srcs/parsing/parsing_toolbox.c                              */
/* ============================================================ */
char	*skip_spaces(char *str);
int		handle_empty_line(char *line, int map_start);
int		is_all_digits(char *str);
void	ft_cub_strlcpy(char *dst, const char *src, size_t dest_siz);
char	*trim_newline(char *s);
int		is_empty_line(char *line);             /* 被调用但未见定义，需要你补 */
int		is_map_line(char *line);               /* 同上 */



#endif