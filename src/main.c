/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:09:49 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/25 22:06:30 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	get_data(t_data *data, char **ag)
{
	data->path_file_1 = ag[1];
	data->cmd1 = ag[2];
	data->cmd2 = ag[3];
	data->path_file_2 = ag[4];
}

char	*find_path(char **envp)
{
	int x;
	int return_path;

	x = 0;
	while (envp[x])
	{
		return_path = ft_strncmp(envp[x], "PATH", 4);
		if (return_path == 0)
			return (envp[x]);
		x++;
	}
	return (NULL);
}

void	create_list(t_data *data)
{
	data->path_list = ft_split(data->path_envp, '=');
	data->path_list = ft_split(data->path_list[1], ':');
}

char	*find_binary(t_data *data)
{
	char	*temp;
	int	res;
	int x;

	x = 0;
	while (data->path_list[x])
	{
		temp = ft_strjoin(data->path_list[x], data->cmd1);
		res = access(temp, X_OK);
		if (res == 0)
			return (temp);
		x++;
	}
	return (NULL);
}

int	main(int ac, char **ag, char **envp)
{
	t_data data;
	char	*path_ok;

	if (ac != 5)
		return (0);
	init_data(&data);
	get_data(&data, ag);
	data.path_envp = find_path(envp);
	if (data.path_envp == NULL)
		error("not find PATH in env\n", &data);
	create_list(&data);
	data.cmd1 = ft_strjoin("/", data.cmd1);
	path_ok = find_binary(&data);
	if (path_ok == NULL)
		error("not find binary\n", &data);
	return (0);
}
