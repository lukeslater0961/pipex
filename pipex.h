/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:49:14 by lslater           #+#    #+#             */
/*   Updated: 2024/02/24 10:56:55 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1

typedef struct s_data
{
	pid_t	pid[1024];
	int		path_error;
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**command_1;
	char	**command_2;
	char	**argv;
}	t_data;

char	**find_paths(char **envp);
int		check_access(char **command, char **envp, t_data *data);
int		ft_open(char **files, t_data *data);
int		ft_parse(t_data *data, char **argv, char **envp);
void	free_paths(char *command_with_slash, char **command_paths, char **cmd);
int		setup_command_1(t_data *data, pid_t *pid, char **envp);
int		setup_command_2(t_data *data, pid_t *pid, char **envp);
void	close_fds(t_data *data);

#endif