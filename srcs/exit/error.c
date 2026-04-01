/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:50:31 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/28 00:11:49 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(t_game *game, const char *errmsg)
{
	ft_printf("Error\n%s\n", errmsg);
	ft_free_all(game);
	exit(1);
}