/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:51:50 by mmeerber          #+#    #+#             */
/*   Updated: 2023/07/13 15:52:34 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_min(unsigned long long n, char *hex)
{
	int	count;

	count = 1;
	if (n >= 16)
		count += ft_hexa_min(n / 16, hex);
	write(1, &hex[n % 16], 1);
	return (count);
}
