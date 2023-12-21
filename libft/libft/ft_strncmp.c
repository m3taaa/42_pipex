/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:47:41 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 13:12:51 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != 0 && x < n)
		x++;
	if (x == n)
		return (0);
	return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
}
