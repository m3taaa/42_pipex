/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:48:42 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:10:08 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (((char *)dst == (char *)src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	while (x < n)
	{
		((char *) dst)[x] = ((char *) src)[x];
		x++;
	}
	return (dst);
}
