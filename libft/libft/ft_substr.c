/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:23:28 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/21 12:46:32 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	x;

	if (!s)
		return (0);
	if (ft_strlen((char *)s) <= start)
		len = 0;
	else if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	res = malloc(len + 1);
	if (!res)
		return (0);
	x = 0;
	while (x < len && s[start])
	{
		res[x] = s[start + x];
		x++;
	}
	res[x] = '\0';
	return (res);
}
