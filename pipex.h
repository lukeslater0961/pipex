/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:49:14 by lslater           #+#    #+#             */
/*   Updated: 2024/02/19 13:38:57 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1


typedef struct s_data
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**command_1;
	char	**command_2;
	char	**argv;
}	t_data;

char	**find_paths(char **envp);
int		check_access(char **command, char **envp);
int		ft_open(char **files, t_data *data);
int		ft_parse(t_data *data, char **argv, char **envp);
void	free_paths(char *command_with_slash, char **command_paths);
int		ex_command_1(t_data *data, pid_t pid, char **envp);
int		ex_command_2(t_data *data, pid_t pid, char **envp);

#endif