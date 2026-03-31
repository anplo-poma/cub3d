/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:03:30 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/31 17:45:08 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


static int is_wall(t_game *game, double x, double y)
{
    int mx;
    int my;

    mx = (int)x;
    my = (int)y;
    if (mx < 0 || my < 0 || my >= game->map.rows || mx >= game->map.cols)
        return (1); // 越界一律视为墙
    if (!game->map.matrix[my])
        return (1);
    return (game->map.matrix[my][mx] == '1');
}


static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x + game->player.player_dir_x * MOVESPEED;
	new_y = game->player.player_y + game->player.player_dir_y * MOVESPEED;
	if (!is_wall(game, new_x + MARGIN, game->player.player_y) &&
        !is_wall(game, new_x - MARGIN, game->player.player_y))
        game->player.player_x = new_x;

    if (!is_wall(game, game->player.player_x, new_y + MARGIN) &&
        !is_wall(game, game->player.player_x, new_y - MARGIN))
        game->player.player_y = new_y;
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x - game->player.player_dir_x * MOVESPEED;
	new_y = game->player.player_y - game->player.player_dir_y * MOVESPEED;
	if (!is_wall(game, new_x + MARGIN, game->player.player_y) &&
        !is_wall(game, new_x - MARGIN, game->player.player_y))
        game->player.player_x = new_x;

    if (!is_wall(game, game->player.player_x, new_y + MARGIN) &&
        !is_wall(game, game->player.player_x, new_y - MARGIN))
        game->player.player_y = new_y;
}

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x - game->player.player_dir_y * MOVESPEED;
	new_y = game->player.player_y + game->player.player_dir_x * MOVESPEED;
	if (!is_wall(game, new_x + MARGIN, game->player.player_y) &&
        !is_wall(game, new_x - MARGIN, game->player.player_y))
        game->player.player_x = new_x;

    if (!is_wall(game, game->player.player_x, new_y + MARGIN) &&
        !is_wall(game, game->player.player_x, new_y - MARGIN))
        game->player.player_y = new_y;
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x + game->player.player_dir_y * MOVESPEED;
	new_y = game->player.player_y - game->player.player_dir_x * MOVESPEED;
	if (!is_wall(game, new_x + MARGIN, game->player.player_y) &&
        !is_wall(game, new_x - MARGIN, game->player.player_y))
        game->player.player_x = new_x;

    if (!is_wall(game, game->player.player_x, new_y + MARGIN) &&
        !is_wall(game, game->player.player_x, new_y - MARGIN))
        game->player.player_y = new_y;
}

//旋转 = 角度相加，角度相加 = cos/sin 的展开式。
/*
(x, y) = (cos α, sin α)
turn angle:
(cos(α+θ), sin(α+θ))
=
cos(α+θ) = cos α · cos θ  -  sin α · sin θ
sin(α+θ) = cos α · sin θ  +  sin α · cos θ

cos α = x，sin α = y

new_x = x · cosθ - y · sinθ
new_y = x · sinθ + y · cosθ

*/
void	rotate_player(t_game * game, double angle)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &game->player;
	old_dir_x = p->player_dir_x;
	p->player_dir_x = old_dir_x * cos(angle) - p->player_dir_y * sin(angle);
	p->player_dir_y = old_dir_x * sin(angle) + p->player_dir_y * cos(angle);
	old_plane_x = p->plane_x;
    p->plane_x = old_plane_x * cos(angle) - p->plane_y * sin(angle);
    p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	move_player(t_game *game)
{
	if (game->move_y == 1)
		move_forward(game);
	if (game->move_y == -1)
		move_backward(game);
	if (game->move_x == -1)
		move_right(game);
	if (game->move_x == 1)
		move_left(game);
	if (game->rotate == 1)
		rotate_player(game, ROTSPEED);   //turn left
    if (game->rotate == -1)
		rotate_player(game, -ROTSPEED); //right
}

