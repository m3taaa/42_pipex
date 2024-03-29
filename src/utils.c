/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:39:05 by mmeerber          #+#    #+#             */
/*   Updated: 2024/01/11 15:31:29 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include <stdlib.h>

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

char	**find_path(char **envp)
{
	int		x;
	int		return_path;
	char	**path;

	x = 0;
	while (envp[x])
	{
		return_path = ft_strncmp(envp[x], "PATH", 4);
		if (return_path == 0)
		{
			path = ft_split(envp[x], '=');
			path = ft_split(path[1], ':');
			return (path);
		}
		x++;
	}
	return (NULL);
}

char	*find_binary(char *binary, char **envp_path)
{
	char	*temp;
	int		res;
	int		x;

	x = 0;
	while (envp_path[x])
	{
		temp = ft_strjoin(envp_path[x], binary);
		res = access(temp, X_OK);
		if (res == 0)
			return (temp);
		x++;
	}
	return (NULL);
}

void	run_cmd(char *ag, char **envp)
{
	char	**args;
	char	**envp_path;
	char	*binary;
	int		return_error;

	envp_path = find_path(envp);
	if (envp_path == NULL)
		error("not find variable PATH in env");
	args = ft_split(ag, ' ');
	binary = ft_strjoin("/", args[0]);
	binary = find_binary(binary, envp_path);
	if (binary == NULL)
		error("command not found\n");
	return_error = execve(binary, args, envp);
	if (return_error == -1)
		error("error execve\n");
}
