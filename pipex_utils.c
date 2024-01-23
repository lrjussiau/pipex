/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:34:38 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/29 07:01:19 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_single_cmd(char *cmd)
{
	char	*single_cmd;
	char	**args;

	if (strncmp(cmd, " ", ft_strlen(cmd)) == 0)
		return (cmd);
	args = ft_split(cmd, ' ');
	single_cmd = ft_strdup(args[0]);
	ft_free_tab(args);
	return (single_cmd);
}

void	close_pipe(int argc, int **fd)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

int	**create_pipe(int argc)
{
	int	i;
	int	**fd;

	i = 0;
	fd = malloc((argc - 2) * sizeof(int *));
	while (i < argc - 2)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (pipe(fd[i]) < 0)
			return (NULL);
		i++;
	}
	return (fd);
}

int	open_file(char *file, int pos)
{
	int	fd_open;

	fd_open = 0;
	if (pos == 1)
	{
		fd_open = open(file, O_RDONLY, 0777);
		if (fd_open == -1)
		{
			return (-1);
		}
	}
	else if (pos == 2)
	{
		fd_open = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_open == -1)
		{
			return (-1);
		}
	}
	return (fd_open);
}
