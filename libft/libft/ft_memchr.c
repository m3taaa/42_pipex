/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:24:19 by mmeerber          #+#    #+#             */
/*   Updated: 2024/01/09 09:36:58 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	if (n)
	{
		while (n--)
			if (*ss++ == (unsigned char)c)
				return (ss - 1);
	}
	return (0);
}
