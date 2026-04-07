/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:03:50 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/04/07 21:49:34 by xuewang          ###   ########.fr       */
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

	i = 0;
	if (dest_siz > 0)
	{
		while (src[i] && i < dest_siz - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
}

// trim_newline

char	*trimnl(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	return (s);
}
