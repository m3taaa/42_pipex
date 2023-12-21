/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:58:13 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 13:27:06 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;
	size_t	len_needle;

	x = 0;
	y = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	while (haystack[x] && x < len)
	{
		if (haystack[x] == needle[y])
		{
			y++;
			if (y == len_needle)
				return ((char *)&haystack[x - y + 1]);
		}
		else
		{
			x -= y;
			y = 0;
		}
		x++;
	}
	return (NULL);
}
