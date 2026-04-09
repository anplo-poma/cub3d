/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <xuewang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:32:38 by xuewang           #+#    #+#             */
/*   Updated: 2026/04/09 14:02:02 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dest_siz)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dest_siz > 0)
	{
		while (src[i] && i < dest_siz - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
//if (!dst || !src)
//return (0);
/*
int	main()
{
	char	dest1[20];
	char	dest2[20];
	const char	*src = "hello worldddddddddddddddddddddddx";
	size_t	res2;
	
	//memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));

	//res1 = strlcpy(dest1, src, 6);
	res2 = ft_strlcpy(dest1, src, 27);
	
	//printf("libc strlcpy : \"%s\", return = %zu\n", dest1, res1);
	printf("ft_strlcpy   : \"%s\", return = %zu\n", dest1, res2);
}
*/
