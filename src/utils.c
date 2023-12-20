/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:39:05 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/20 10:32:32 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	error(char *msg)
{
	write(2, msg, strlen(msg));
}

void	print_data(t_data *data)
{
	printf("path file1 = %s\n", data->path_file_1);
	printf("path file2 = %s\n", data->path_file_2);
	printf("cmd1 = %s\n", data->cmd1);
	printf("cmd2 = %s\n", data->cmd2);
}
