/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:27:30 by lslater           #+#    #+#             */
/*   Updated: 2024/02/20 13:58:17 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ex_command_1(t_data *data, pid_t *pid, char **envp)
{
	if (pipe(data->pipefd) == -1)
	{
		perror("./pipex");
		exit (EXIT_FAILURE);
	}
	printf("in %d, out %d, pipe read %d, pipe write %d\n", data->infile, data->outfile, data->pipefd[0], data->pipefd[1]);
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (*pid == 0)
	{
		if (dup2(data->infile, STDIN) == -1)
		{
			perror("dup2");
			exit (EXIT_FAILURE);
		}
		if (dup2(data->pipefd[1], STDOUT) == -1)
		{
			perror("dup2");
			exit (EXIT_FAILURE);
		}
		close_fds(data);
		execve(data->command_1[0], data->command_1, envp);
		ft_free_tab(data->command_1);
		ft_free_tab(data->command_2);
		perror("execve");
		exit (1);
	}
	ft_printf("im parent = %d\n", getpid());//to be removed
	return (0);
}

int	ex_command_2(t_data *data, pid_t *pid, char **envp)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (*pid == 0)
	{
		if (dup2(data->pipefd[0], STDIN) == -1)
		{
			perror("dup2");
			exit (EXIT_FAILURE);
		}
		if (dup2(data->outfile, STDOUT) == -1)
		{
			perror("dup2");
			exit (EXIT_FAILURE);
		}
		close_fds(data);
		execve(data->command_2[0], data->command_2, envp);
		ft_free_tab(data->command_1);
		ft_free_tab(data->command_2);
		free(data);
		perror("execve");
		exit (1);
	}
	ft_printf("im parent = %d\n", getpid());//to be removed
	return (0);
}
