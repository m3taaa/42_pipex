/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:09:57 by mmeerber          #+#    #+#             */
/*   Updated: 2024/01/09 09:33:56 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft_and_more.h"

void	error(char *msg);
void	run_cmd(char *ag, char **envp);
char	**find_path(char **envp);
char	*find_binary(char *binary, char **envp_path);

#endif
