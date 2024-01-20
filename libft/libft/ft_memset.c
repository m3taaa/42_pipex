/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:36:50 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:12:17 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	size_t	x;

	x = 0;
	while (x < len)
	{
		((unsigned char *) d)[x] = (unsigned char) c;
		x++;
	}
	return (d);
}
