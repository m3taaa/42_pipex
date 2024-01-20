/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:56:06 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:57:17 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_string(size_t len, size_t count, char *dst, char const *s)
{
	size_t	x;

	x = 0;
	while (len > 0)
	{
		dst[x + count] = s[x];
		x++;
		len--;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	x;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1);
	if (!res)
		return (0);
	x = 0;
	add_string(len_s1, x, res, s1);
	x += len_s1;
	add_string(len_s2, x, res, s2);
	x += len_s2;
	res[x] = '\0';
	return (res);
}
