/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:02:30 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:11:40 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				x;
	unsigned char	temp;

	x = 0;
	if (((char *)dst == (char *)src) || len == 0)
		return (dst);
	if (src < dst)
	{
		x = (int)len - 1;
		while (x >= 0)
		{
			((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
			x--;
		}
		return (dst);
	}
	while (x < (int)len)
	{
		temp = ((unsigned char *) src)[x];
		((unsigned char *) dst)[x] = temp;
		x++;
	}
	return (dst);
}
