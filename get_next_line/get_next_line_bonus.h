/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:28:03 by xuewang           #+#    #+#             */
/*   Updated: 2025/06/02 19:37:20 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*lib*/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

/*just in case*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*functions main*/
char	*get_next_line(int fd);

/*functions help*/
void	*ft_free(char **ptr1, char **ptr2);
int		detect_stop(char *storage);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);

#endif
