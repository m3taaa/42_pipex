/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:03:39 by mmeerber          #+#    #+#             */
/*   Updated: 2023/08/01 10:23:59 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	x;

	x = 0;
	if (n <= 0)
		return ;
	while (x < n)
	{
		((unsigned char *) s)[x] = '\0';
		x++;
	}
}

static	int	n_is_nega(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putnbr(long long n)
{
	char	nb[13];
	int		tab_int[3];

	tab_int[2] = 0;
	if (n < 0)
		tab_int[0] = 1;
	else
		tab_int[0] = 0;
	ft_bzero(nb, 13);
	if (n == 0)
		nb[0] = '0';
	tab_int[1] = 0;
	while (n != 0)
	{
		nb[tab_int[1]++] = '0' + n_is_nega(n % 10);
		n = (n / 10);
	}
	if (tab_int[0])
		nb[tab_int[1]] = '-';
	else if (tab_int[1] > 0)
		tab_int[1]--;
	while (tab_int[1] >= 0)
		tab_int[2] += write(1, &nb[tab_int[1]--], 1);
	return (tab_int[2]);
}

/*
 * tab_int[0] = permet de savoir si c'est un nombre positif ou négatif
 * tab_int[1] = Occurence pour se déplacer dans la variable nb
 * tab_int[2] = Nombre de caractère à retourner
 */
