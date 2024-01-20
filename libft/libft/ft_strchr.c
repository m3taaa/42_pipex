/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:27:05 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:53:41 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == (char)c)
			return ((char *)(s + x));
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)(s + x));
	return (NULL);
}
