/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:23:21 by xuewang           #+#    #+#             */
/*   Updated: 2025/05/28 13:45:10 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);

static int	sub_printf_nbr(long nbr, int *count)
{
	int	ret;

	if (nbr >= 10)
	{
		ret = sub_printf_nbr(nbr / 10, count);
		if (ret == -1)
			return (-1);
	}
	ret = ft_putchar((nbr % 10) + '0');
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

int	ft_printf_nbr(int n)
{
	int		count;
	int		ret;
	long	nbr;

	count = 0;
	nbr = n;
	ret = 0;
	if (nbr < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		count += ret;
		nbr = -nbr;
	}
	ret = sub_printf_nbr(nbr, &count);
	if (ret == -1)
		return (-1);
	return (count);
}
