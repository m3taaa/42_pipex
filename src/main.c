/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:32:04 by mmeerber          #+#    #+#             */
/*   Updated: 2024/01/05 15:44:29 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void	child_process(int *fd, char **ag, char **envp)
{
	int	fd_child;
	int	return_error;

	fd_child = open(ag[1], O_RDONLY);
	if (fd_child == -1)
		error("file not found\n");
	return_error = dup2(fd_child, STDIN_FILENO);
	if (return_error == -1)
		error("dup2 error\n");
	return_error = dup2(fd[1], STDOUT_FILENO);
	if (return_error == -1)
		error("dup2 error\n");
	close(fd[0]);
	run_cmd(ag[2], envp);
	close(fd_child);
	close(fd[1]);
}

static void	parent_process(int *fd, char **ag, char **envp, pid_t child)
{
	int	status;
	int	fd_parent;
	int	return_error;

	fd_parent = open(ag[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd_parent == -1)
		error("error open outfile\n");
	return_error = waitpid(child, &status, 0);
	if (return_error == -1)
		error("waitpid error\n");
	return_error = dup2(fd[0], STDIN_FILENO);
	if (return_error == -1)
		error("dup2 error\n");
	return_error = dup2(fd_parent, STDOUT_FILENO);
	if (return_error == -1)
		error("dup2 error\n");
	close(fd[1]);
	run_cmd(ag[3], envp);
	close(fd_parent);
	close(fd[0]);
}

int	main(int ac, char **ag, char **envp)
{
	int		fd[2];
	pid_t	child;

	if (ac != 5)
		error("Error syntax pipex\n");
	if (pipe(fd) == -1)
		error("pip error\n");
	child = fork();
	if (child == -1)
		error("fork error\n");
	if (child == 0)
		child_process(fd, ag, envp);
	else
		parent_process(fd, ag, envp, child);
	exit(EXIT_SUCCESS);
}
