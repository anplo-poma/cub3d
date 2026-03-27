/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:20:22 by xuewang           #+#    #+#             */
/*   Updated: 2025/05/27 18:12:58 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_c(char c)
{
	if (write (1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_printf_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	dispatch(va_list ap, char spe)
{
	int	count;

	count = 0;
	if (spe == 'c')
		count = ft_printf_c(va_arg(ap, int));
	else if (spe == 's')
		count += ft_printf_str(va_arg(ap, char *));
	else if (spe == 'p')
		count += ft_printf_ptr((unsigned long long)va_arg(ap, void *));
	else if ((spe == 'i') || (spe == 'd'))
		count += ft_printf_nbr(va_arg(ap, int));
	else if (spe == 'u')
		count += ft_printf_unsigned(va_arg(ap, unsigned int));
	else if ((spe == 'x') || (spe == 'X'))
		count += ft_printf_hex(va_arg(ap, unsigned int), spe);
	else if (spe == '%')
		count += ft_printf_c('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		temp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	temp = 0;
	va_start(ap, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			temp = dispatch(ap, input[i + 1]);
			i++;
		}
		else
			temp = ft_printf_c(input[i]);
		if (temp < 0)
			return (-1);
		count += temp;
		i++;
	}
	va_end(ap);
	return (count);
}
