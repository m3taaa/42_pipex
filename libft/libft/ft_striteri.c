/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:54:42 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/10 12:55:44 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	x;

	if (!s || (!s && !f))
		return ;
	if (!f)
		return ;
	x = 0;
	while (s[x])
	{
		(*f)(x, &s[x]);
		x++;
	}
}
