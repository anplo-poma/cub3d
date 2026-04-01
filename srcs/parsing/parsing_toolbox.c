/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:03:50 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/28 00:54:43 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;
    return (str);
}

// without free version(free once in gnl)
int	handle_empty_line(t_game *game, char *line, int map_start)
{
	if (!is_empty_line(line))
		return (0);
	if (map_start == 1)
		ft_error(game, "empty line in map");
	return (1);
}
/*
int  handle_empty_line(char *line, int map_start)
{
	if (!is_empty_line(line))
		return (0);
	if (map_start == 1)
	{
		free(line);
		ft_error("error msg: empty line in map");
	}
	free(line);
	return (1);
}
*/
int	is_all_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_cub_strlcpy(char *dst, const char *src, size_t dest_siz)
{
	size_t	i;
	//size_t	len;

	i = 0;
	//len = ft_strlen(src);
	if (dest_siz > 0)
	{
		while (src[i] && i < dest_siz - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
}

char *trim_newline(char *s)
{
	int len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	return s;
}