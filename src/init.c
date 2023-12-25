/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:41:02 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/25 17:32:23 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init_data(t_data *data)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->path_file_1 = NULL;
	data->path_file_2 = NULL;
	data->path_envp = NULL;
	data->path_list = NULL;
	data->first_command = NULL;
	data->second_command = NULL;
}
