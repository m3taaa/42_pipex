/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:51:06 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/16 18:04:15 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	char_start_string(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && (str[x] == 32 || str[x] == '\t' || str[x] == '\n'
			||str[x] == '\r' || str[x] == '\v' || str[x] == '\f'))
		x++;
	return (x);
}

int	ft_atoi(const char *str)
{
	long	nb;
	int		x;
	int		nega;
	long	temp;

	nb = 0;
	x = 0;
	nega = 1;
	x = char_start_string(str);
	if (str[x] == '-' && str[x] != '\0' && ++x)
		nega = -1;
	else if (str[x] == '+' && str[x] != '\0')
		x++;
	while (ft_isdigit(str[x]) && str[x] != '\0')
	{
		temp = nb;
		nb = (nb * 10) + (str[x++] - '0');
		if (temp > nb && nega == 1)
			return (-1);
		if (temp > nb && nega == -1)
			return (0);
	}
	return ((int)nb * nega);
}
