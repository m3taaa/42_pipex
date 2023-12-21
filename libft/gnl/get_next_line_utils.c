/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:25:45 by mmeerber          #+#    #+#             */
/*   Updated: 2023/09/11 13:25:47 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_gnl(s1) + ft_strlen_gnl(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(s1) + ft_strlen_gnl(buff)] = '\0';
	free(s1);
	return (str);
}

char	*backup(char *content)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!content)
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen_gnl(content) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (content[i])
		str[j++] = content[i++];
	str[j] = '\0';
	free(content);
	return (str);
}
