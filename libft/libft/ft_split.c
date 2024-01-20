/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:39:09 by mmeerber          #+#    #+#             */
/*   Updated: 2023/05/21 14:00:02 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_tab_2d(char **res)
{
	int	x;

	x = 0;
	while (res[x])
	{
		free(res[x]);
		x++;
	}
	free(res);
}

static	int	count_words(char const *s, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
			count++;
		while (s[x] != c && s[x] != '\0')
			x++;
	}
	return (count);
}

static	int	create_new_list(char const *s, char c, char **res, int word)
{
	int	x;
	int	start;
	int	new_word;

	new_word = 0;
	x = 0;
	while (new_word < word)
	{
		while (s[x] == c)
			x++;
		start = x;
		while (s[x] != c && s[x] != '\0')
			x++;
		res[new_word] = ft_substr(s, start, x - start);
		if (!res[new_word])
			return (0);
		new_word++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**res;
	int		result;

	nb_words = 0;
	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	result = create_new_list(s, c, res, nb_words);
	if (result == 0)
	{
		free_tab_2d(res);
		return (NULL);
	}
	res[nb_words] = NULL;
	return (res);
}
