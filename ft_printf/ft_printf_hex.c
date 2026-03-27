/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:26:33 by xuewang           #+#    #+#             */
/*   Updated: 2025/05/28 13:44:19 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);

int	ft_printf_hex(unsigned int n, char spe)
{
	int		count;
	char	c;
	int		ret;

	ret = 0;
	count = 0;
	c = '0';
	if (n >= 16)
	{
		ret = ft_printf_hex(n / 16, spe);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if ((n % 16) < 10)
		c = (n % 16) + '0';
	else if (spe == 'x')
		c = (n % 16) - 10 + 'a';
	else if (spe == 'X')
		c = (n % 16) - 10 + 'A';
	ret = ft_putchar(c);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
