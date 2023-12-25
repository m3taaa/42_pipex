/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:09:49 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/23 18:03:16 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init_data(t_data *data)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->path_file_1 = NULL;
	data->path_file_2 = NULL;
}

void	get_data(t_data *data, char **ag)
{
	data->path_file_1 = ag[1];
	data->cmd1 = ag[2];
	data->cmd2 = ag[3];
	data->path_file_2 = ag[4];
}

int	main(int ac, char **ag)
{
	t_data data;

	if (ac != 5)
		return (0);
	init_data(&data);
	get_data(&data, ag);
	check_file(&data);
	execv(data.cmd1, ag);
	return (0);
}
