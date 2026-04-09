/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:54:23 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/09 13:59:40 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	i;

	dest = (void *)malloc(nmemb * size);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)dest)[i] = '\0';
		i++;
	}
	return (dest);
}
/*
        if (nmemb == 0 || size == 0)
                return (NULL);
        if (nmemb > SIZE_MAX / size)
                return (NULL);
	if (nmemb != 0 && size > SIZE_MAX / nmemb)
                return (NULL);
*/
