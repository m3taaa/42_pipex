/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:50:46 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 13:14:06 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	while (x >= 0)
	{
		if (s[x] == (char)c)
			return ((char *)(s + x));
		x--;
	}
	return (NULL);
}
