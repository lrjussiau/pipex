/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:42:49 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/28 10:04:04 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

void	ft_free_tab(char **tab);
char	*find_path(char *cmd, char **envp);
char	*get_single_cmd(char *cmd);
void	close_pipe(int argc, int **fd);
void	execute(char *cmd, char **envp);
int		**create_pipe(int argc);
int		main(int argc, char **argv, char **envp);
int		open_file(char *file, int pos);
void	pipex(int argc, char **argv, char **envp);

#endif