/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:39:05 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/20 12:30:33 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error(char *msg, t_data *data)
{
	if (data->fd_file_1 < 0)
		close(data);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	print_data(t_data *data)
{
	printf("path file1 = %s\n", data->path_file_1);
	printf("path file2 = %s\n", data->path_file_2);
	printf("cmd1 = %s\n", data->cmd1);
	printf("cmd2 = %s\n", data->cmd2);
}
