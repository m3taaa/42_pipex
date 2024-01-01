#include "../header/pipex.h"

char	*find_path(char **envp)
{
	int	x;
	int	path;

	x = 0;
	while (envp[x])
	{
		path = ft_strncmp(envp[x], "PATH", 4);
		if (path == 0)
			return (envp[x]);
		x++;
	}
	return 0;
}

char	*search_binary(t_data *data)
{
	int		res;
	int		x;
	char	*temp;

	x = 0;
	while (data->path[x])
	{
		temp = ft_strjoin(data->path[x], data->binary);
		res = access(temp, X_OK);
		if (res == 0)
			return (temp);
		x++;
	}
	return (0);
}

void	get_data(char **ag, t_data *data, char **envp)
{
	char	**temp;
	char	*path;

	temp = ft_split(ag[2], ' ');
	data->binary = temp[0];
	data->binary = ft_strjoin("/", data->binary);
	data->arg = temp[1];
	data->file = ag[1];
	path = find_path(envp);
	if (path == 0)
		error("not find PATH in envp\n");
	data->path = ft_split(path, '=');
	data->path = ft_split(data->path[1], ':');
	data->path_binary = search_binary(data);
	if (data->path_binary == 0)
		error("not found binary\n");
	printf("end of get_data\n");
}

int	main(int ac, char **ag, char **envp)
{
	t_data data;
	if (ac != 5)
		error("Error start pipex\n");
	get_data(ag, &data, envp);
	//execve(data.path_binary, );
	printf("end\n");
	return (0);
}
