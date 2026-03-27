/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:04:46 by xuewang           #+#    #+#             */
/*   Updated: 2025/08/26 23:25:06 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//INCLUDES
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*functions main*/
char	*get_next_line(int fd);

/*functions help*/
void	*ft_free(char **ptr1, char **ptr2);
int		detect_stop(char *storage);
//char	*ft_strdup(char *str);
//char	*ft_strjoin(char *s1, char *s2);
//int		ft_strlen(char *s);

#endif
