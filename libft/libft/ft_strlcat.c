/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:13:53 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:58:24 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	x;

	len_dst = 0;
	len_src = 0;
	x = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (src[x] != '\0' && len_dst + x < dstsize - 1)
	{
		dst[len_dst + x] = src[x];
		x++;
	}
	dst[len_dst + x] = '\0';
	return (len_dst + len_src);
}
