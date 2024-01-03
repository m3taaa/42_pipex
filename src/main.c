#include "../header/pipex.h"
#include <stdlib.h>

char	**find_path(char **envp)
{
	int x;
	int return_path;
	char	**path;

	x = 0;
	while (envp[x])
	{
		return_path = ft_strncmp(envp[x], "PATH", 4);
		if (return_path == 0)
		{
			path = ft_split(envp[x], '=');
			path = ft_split(path[1], ':');
			return (path);
		}
		x++;
	}
	return (NULL);
}

char	*find_binary(char *binary, char **envp_path)
{
	char	*temp;
	int	res;
	int x;

	x = 0;
	while (envp_path[x])
	{
		temp = ft_strjoin(envp_path[x], binary);
		res = access(temp, X_OK);
		if (res == 0)
			return (temp);
		x++;
	}
	return (NULL);
}

void	run_cmd(char *ag, char **envp)
{
	char	**args;
	char	**envp_path;
	char	*binary;

	envp_path = find_path(envp);
	if (envp_path == NULL)
		error("not find variable PATH in env");
	args = ft_split(ag, ' ');
	binary = ft_strjoin("/", args[0]);
	binary = find_binary(binary, envp_path);
	execve(binary, args, envp);
}

int	main(int ac, char **ag, char **envp)
{
	pid_t	child;
	int		fd[2];
	int		status;
	int		return_error;
	int		fd_child;
	int		fd_parent;

	if (ac < 5)
		error("Error syntax pipex\n");
	return_error = pipe(fd);
	if (return_error == -1)
		error("pip error\n");
	child = fork();
	if (child == 0)
	{
		fd_child = open(ag[1], O_RDONLY, 0777);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_child, STDIN_FILENO);
		close(fd[0]);
		run_cmd(ag[2], envp);
	}
	else
	{
		fd_parent = open(ag[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		return_error = waitpid(child, &status, 0);
		if (return_error == -1)
			error("waitpid error\n");
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_parent, STDOUT_FILENO);
		close(fd[1]);
		run_cmd(ag[3], envp);
	}
	return (0);
}
