/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:07:15 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/31 17:31:39 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
        ft_free_all(game);//later
		exit(0);
	}
	if (keycode == KEY_W)
		game->move_y = 1;
	if (keycode == KEY_S)
		game->move_y = -1;
	if (keycode == KEY_A)
		game->move_x = -1;
	if (keycode == KEY_D)
		game->move_x = 1;
	if (keycode == KEY_LEFT)
		game->rotate = -1;
    if (keycode == KEY_RIGHT)
		game->rotate = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W && game->move_y == 1)
		game->move_y = 0;
	if (keycode == KEY_S && game->move_y == -1)
		game->move_y = 0;
	if (keycode == KEY_A && game->move_x == -1)
		game->move_x = 0;
	if (keycode == KEY_D && game->move_x == 1)
		game->move_x = 0;
	if (keycode == KEY_LEFT  && game->rotate == -1)
		game->rotate = 0;
    if (keycode == KEY_RIGHT && game->rotate == 1) 
		game->rotate = 0;
	return (0);
}

int	close_window(t_game *game)
{
	//game->win = NULL;
    ft_free_all(game);//later
	exit(0);
	return (0);
}

static int	game_loop(t_game *game)
{
	move_player(game);
	render_frame(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, close_window, game);
	mlx_loop_hook(game->mlx, game_loop, game);
}