/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuewang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:36:36 by xuewang           #+#    #+#             */
/*   Updated: 2025/05/28 13:40:28 by xuewang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*function*/

int	ft_putchar(char c);
int	ft_printf_c(char c);
int	ft_printf_str(char *str);
int	dispatch(va_list ap, char spe);
int	ft_printf(const char *input, ...);

/*sub function*/
int	ft_printf_nbr(int nbr);
int	ft_printf_hex(unsigned int n, char spe);
int	ft_printf_ptr(unsigned long long ptr);
int	ft_printf_unsigned(unsigned int nbr);

#endif
