/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:32:04 by mmeerber          #+#    #+#             */
/*   Updated: 2024/01/04 13:28:16 by mmeerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	child_process(int	*fd, char **ag, char **envp)
{
	int fd_child;

	fd_child = open(ag[1], O_RDONLY, 0777);
	if (fd_child == -1)
		error("file not found\n");
	dup2(fd_child, STDOUT_FILENO);
	dup2(fd[1], STDIN_FILENO);
	close(fd[0]);
	run_cmd(ag[2], envp);
}

void	parent_process(int *fd, char **ag, char **envp, pid_t child)
{
	int fd_parent;
	int	status;
	int	return_error;

	fd_parent = open(ag[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	return_error = waitpid(child, &status, 0);
	if (return_error == -1)
		error("waitpid error\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_parent, STDOUT_FILENO);
	close(fd[1]);
	run_cmd(ag[3], envp);
}

int	main(int ac, char **ag, char **envp)
{
	pid_t	child;
	int		fd[2];
	int		return_error;

	if (ac < 5)
		error("Error syntax pipex\n");
	return_error = pipe(fd);
	if (return_error == -1)
		error("pip error\n");
	child = fork();
	if (child == 0)
		child_process(fd, ag, envp);
		/*fd_child = open(ag[1], O_RDONLY, 0777);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_child, STDIN_FILENO);
		close(fd[0]);
		run_cmd(ag[2], envp);*/
	else
		parent_process(fd, ag, envp, child);
		/*fd_parent = open(ag[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		return_error = waitpid(child, &status, 0);
		if (return_error == -1)
			error("waitpid error\n");
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_parent, STDOUT_FILENO);
		close(fd[1]);
		run_cmd(ag[3], envp);*/
	return (0);
}
