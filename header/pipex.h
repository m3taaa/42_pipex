/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:09:57 by mmeerber          #+#    #+#             */
/*   Updated: 2023/12/25 17:57:02 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft_and_more.h"

typedef struct s_data
{
	char	*binary;
	char	**arg;
	char	*file;
	char	**path;
	char	*path_binary;
} t_data;

void	error(char *msg);
void	init_data();

#endif
