/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:03:03 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/09 10:55:23 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **ptr1, char **ptr2);
int		detect_stop(char *storage);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);

char	*cut_before_slashn(char *storage)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	if (!storage)
		return (NULL);
	len = 0;
	while (storage[len] && storage[len] != '\n')
	{
		len++;
	}
	if (storage[len] == '\n')
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		dest[i++] = storage[j++];
	}
	dest[len] = '\0';
	return (dest);
}

char	*cut_after_slashn(char *storage)
{
	int		i;
	int		len;
	int		j;
	char	*dest;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (NULL);
	i++;
	len = ft_strlen(storage);
	if (i >= len)
		return (NULL);
	dest = malloc(sizeof(char) * (len - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (storage[i])
		dest[j++] = storage[i++];
	dest[j] = '\0';
	return (dest);
}

char	*save_from_buffer(int fd, char *storage)
{
	char	*buf_read;
	int		bytes_read;
	char	*temp;

	if (!storage)
		storage = ft_strdup("");
	buf_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_read)
		return (NULL);
	bytes_read = 1;
	while (detect_stop(storage) != 1 && bytes_read > 0)
	{
		bytes_read = read(fd, buf_read, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&buf_read, &storage));
		buf_read[bytes_read] = '\0';
		temp = ft_strjoin(storage, buf_read);
		if (!temp)
			return (ft_free(&buf_read, &storage));
		free(storage);
		storage = temp;
	}
	free(buf_read);
	return (storage);
}

char	*storage_to_output(char *storage)
{
	if (!storage || storage [0] == '\0')
		return (NULL);
	if (!detect_stop(storage))
		return (ft_strdup(storage));
	return (cut_before_slashn(storage));
}

char	*get_next_line(int fd)
{
	static char	*restbuf = NULL;
	char		*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(NULL, &restbuf));
	storage = save_from_buffer(fd, restbuf);
	if (!storage)
		return (ft_free(NULL, &restbuf));
	if (storage[0] == '\0')
	{
		free(storage);
		restbuf = NULL;
		return (NULL);
	}
	line = storage_to_output(storage);
	restbuf = cut_after_slashn(storage);
	if (!restbuf)
		restbuf = ft_strdup("");
	free(storage);
	return (line);
}
/*
char	*get_next_line(int fd)
{
	static char	*restbuf = NULL;
	char		*storage;
	char		*line;

	//if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(NULL, &restbuf));
	storage = save_from_buffer(fd, restbuf);
	if (!storage)
		return (ft_free(NULL, &restbuf));
	if (storage[0] == '\0')
	{
		free(storage);//cnahge
    	restbuf = NULL;//change
    	return (NULL);//change
		//ft_free(&storage, &restbuf);
		//return (NULL);
	}
	line = storage_to_output(storage);
	restbuf = cut_after_slashn(storage);
	if (!restbuf)//add
    	restbuf = ft_strdup("");//add
	free(storage);
	return (line);
}
	*/