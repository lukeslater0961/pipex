/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:27:30 by lslater           #+#    #+#             */
/*   Updated: 2024/02/29 13:54:23 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	command_exec1(t_data *data, char **envp)
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
	close_fds(data, 1);
	execve(data->command_1[0], data->command_1, envp);
	ft_free_tab(data->command_1);
	ft_free_tab(data->command_2);
	free(data);
	exit (1);
}

int	setup_command_1(t_data *data, pid_t *pid, char **envp)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (*pid == 0)
		command_exec1(data, envp);
	return (0);
}

void	command_exec2(t_data *data, char **envp)
{
	if (!(*data->command_2))
		data->command_2[0] = ft_strdup("");
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
	close_fds(data, 1);
	execve(data->command_2[0], data->command_2, envp);
	ft_free_tab(data->command_1);
	ft_free_tab(data->command_2);
	free(data);
	exit (1);
}

int	setup_command_2(t_data *data, pid_t *pid, char **envp)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (*pid == 0)
		command_exec2(data, envp);
	return (0);
}
