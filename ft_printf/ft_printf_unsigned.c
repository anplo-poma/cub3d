/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:32:51 by xuewang           #+#    #+#             */
/*   Updated: 2025/05/28 13:39:58 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);
/*
int	ft_printf_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_printf_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
*/

int	ft_printf_unsigned(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	ret = 0;
	if (n >= 10)
	{
		ret = ft_printf_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
