/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:54:59 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:02:25 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_nega(long a)
{
	if (a < 0)
		return (0);
	return (1);
}

static	int	len_nb(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= 1)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static	char	*convert(long nb, int len, char *res)
{
	int	nb_is_nega;

	if (nb == 0)
		return (res = ft_strdup("0"));
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	nb_is_nega = is_nega(nb);
	if (nb_is_nega == 0)
		nb = -nb;
	res[len] = '\0';
	len--;
	while (len > 0)
	{
		res[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (nb_is_nega == 0)
		res[len] = '-';
	else
		res[len] = (nb % 10) + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	nb;

	nb = n;
	result = 0;
	len = len_nb(nb);
	result = convert(nb, len, result);
	if (!result)
		return (0);
	return (result);
}
