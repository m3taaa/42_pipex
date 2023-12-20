/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:09:57 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/20 10:32:48 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_data
{
	char	*path_file_1;
	char	*path_file_2;
	char	*cmd1;
	char	*cmd2;
	int		fd_file_1;
	int		fd_file_2;
} t_data;

void	error(char *msg);
void	check_file(t_data *data);
//DEV
void	print_data(t_data *data);

#endif
