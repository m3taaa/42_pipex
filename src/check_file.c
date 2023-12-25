/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:30:53 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/23 17:38:31 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	check_file(t_data *data)
{
	data->fd_file_1 = open(data->path_file_1, O_WRONLY);
	if (data->fd_file_1 < 0)
		error("no such file or directory\n", data);
	return ;
}
