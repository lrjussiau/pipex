/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:45:37 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/29 06:54:47 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**path_to_test;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
	{	
		i++;
	}
	path_to_test = ft_split(envp[i], ':');
	i = 0;
	while (path_to_test[i] != NULL)
	{
		path = ft_strjoin(path_to_test[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(path_to_test);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	path = find_path(get_single_cmd(cmd), envp);
	args = ft_split(cmd, ' ');
	execve(path, args, NULL);
	ft_free_tab(args);
	free(path);
	perror("Command not found");
	exit(EXIT_FAILURE);
}

int	child_process(int argc, int **fd, int num_child, char **argv)
{
	int	fd_open;

	if (num_child == 0)
	{
		fd_open = open_file(argv[1], 1);
		if (fd_open == -1)
			return (1);
		dup2(fd_open, STDIN_FILENO);
	}
	else
		dup2(fd[num_child][0], STDIN_FILENO);
	if (num_child == (argc - 4))
	{
		fd_open = open_file(argv[argc - 1], 2);
		if (fd_open == -1)
			return (1);
		dup2(fd_open, STDOUT_FILENO);
	}
	else
		dup2(fd[num_child + 1][1], STDOUT_FILENO);
	close_pipe(argc, fd);
	return (0);
}

void	pipex(int argc, char **argv, char **envp)
{
	int	**fd;
	int	i;
	int	pid;

	i = 0;
	fd = create_pipe(argc);
	while (i < (argc - 3))
	{
		pid = fork();
		if (pid == 0)
		{
			if (child_process(argc, fd, i, argv) != 0)
			{
				perror("Child process failed");
				exit(EXIT_FAILURE);
			}
			execute(argv[i + 2], envp);
		}
		else if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		pipex(argc, argv, envp);
	else
	{
		perror("Input not valid");
		exit(EXIT_FAILURE);
	}
	return (0);
}
