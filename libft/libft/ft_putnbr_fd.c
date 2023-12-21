/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:43:44 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:45:32 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	n_is_nega(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nb[13];
	int		is_nega;
	int		x;

	if (n < 0)
		is_nega = 1;
	else
		is_nega = 0;
	ft_bzero(nb, 13);
	if (n == 0)
		nb[0] = '0';
	x = 0;
	while (n != 0)
	{
		nb[x++] = '0' + n_is_nega(n % 10);
		n = (n / 10);
	}
	if (is_nega)
		nb[x] = '-';
	else if (x > 0)
		x--;
	while (x >= 0)
		write(fd, &nb[x--], 1);
}
