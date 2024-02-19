/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:27:30 by lslater           #+#    #+#             */
/*   Updated: 2024/02/19 14:17:08 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ex_command_1(t_data *data, pid_t pid, char **envp)
{
	if (pipe(data->pipefd) == -1)
	{
		perror("./pipex");
		exit (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (dup2(data->infile, STDIN) == -1 || dup2(data->pipefd[1], STDOUT) == -1)
		{
			perror("dup2");
			exit (EXIT_FAILURE);
		}
		execve(data->command_1[0], ft_split(data->argv[2], ' '), envp);
		perror("execve");
		exit (1);
	}
    close(data->pipefd[0]);
    close(data->pipefd[1]);
    if (data->infile >= 0)
		close(data->infile);
	if (data->outfile >= 0)
		close(data->outfile);
	ft_printf("im parent = %d\n", getpid());//to be removed
	return (0);
}

int	ex_command_2(t_data *data, pid_t pid, char **envp)
{
	if (pipe(data->pipefd) == -1)
	{
		perror("./pipex");
		exit (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (dup2(data->pipefd[0], STDIN) == -1 || dup2(data->outfile, STDOUT) == -1)
		{
			perror("dup2");
			exit (EXIT_FAILURE);
		}
		execve(data->command_2[0], ft_split(data->argv[3], ' '), envp);
		perror("execve");
		exit (1);
	}
    // close(data->pipefd[0]);
    // close(data->pipefd[1]);
    // // if (data->infile >= 0)
	// // 	close(data->infile);
	// // if (data->outfile >= 0)
	// // 	close(data->outfile);
	ft_printf("im parent = %d\n", getpid());//to be removed
	return (0);
}
