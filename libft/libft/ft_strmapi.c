/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:00:52 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 13:02:48 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	char			*res;

	if (!s || (!s && !f))
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup((char *)s));
	res = ft_strdup((char *)s);
	if (!res)
		return (0);
	x = 0;
	while (s[x] != '\0')
	{
		res[x] = (*f)(x, res[x]);
		x++;
	}
	return (res);
}
