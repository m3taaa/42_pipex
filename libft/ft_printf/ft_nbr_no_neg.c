/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_no_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:58:01 by mmeerber          #+#    #+#             */
/*   Updated: 2023/07/15 15:52:51 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_no_neg(long long nb)
{
	int				count;
	unsigned long	x;

	x = 4294967295;
	if (nb < 0)
	{
		nb += 1;
		x = x - (-nb);
		nb = x;
	}
	count = 0;
	count = ft_putnbr(nb);
	return (count);
}
