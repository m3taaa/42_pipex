/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_maj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:34:44 by mmeerber          #+#    #+#             */
/*   Updated: 2023/07/13 15:49:24 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_maj(unsigned int n, char *hex)
{
	int	count;

	count = 1;
	if (n >= 16)
		count += ft_hexa_min(n / 16, hex);
	write(1, &hex[n % 16], 1);
	return (count);
}
