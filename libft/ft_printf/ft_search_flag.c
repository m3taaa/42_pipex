/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:31:25 by mmeerber          #+#    #+#             */
/*   Updated: 2023/07/15 15:58:23 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_flag(char c, int *count, va_list *ag)
{
	if (c == 'c')
		*count += ft_putchar((char)va_arg(*ag, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(*ag, char *));
	else if (c == 'p' || c == 'x')
	{
		if (c == 'p')
		{
			*count += write (1, "0x", 2);
			*count += ft_hexa_min(va_arg(*ag, unsigned long long), \
					"0123456789abcdef");
		}
		else
			*count += ft_hexa_min(va_arg(*ag, unsigned int), \
					"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(*ag, int));
	else if (c == 'u')
		*count += ft_nbr_no_neg(va_arg(*ag, int));
	else if (c == 'X')
		*count += ft_hexa_maj(va_arg(*ag, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		*count += write(1, "%", 1);
	return ;
}
