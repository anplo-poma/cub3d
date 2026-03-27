/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:28:38 by xuewang           #+#    #+#             */
/*   Updated: 2025/05/28 13:46:59 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf_str(char *str);

int	ft_putchar(char c);

static int	ft_putptr_h(unsigned long long ptr, int *count)
{
	int		ret;
	char	c;

	ret = 0;
	c = '0';
	if (ptr >= 16)
	{
		ret = ft_putptr_h(ptr / 16, count);
		if (ret == -1)
			return (-1);
	}
	if ((ptr % 16) < 10)
		c = (ptr % 16) + '0';
	else
		c = (ptr % 16) - 10 + 'a';
	ret = ft_putchar(c);
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	count;
	int	ret;

	count = 0;
	ret = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count = 0;
	ret = ft_printf_str("0x");
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_putptr_h(ptr, &count);
	if (ret == -1)
		return (-1);
	return (count);
}
