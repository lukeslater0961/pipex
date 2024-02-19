/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:38:48 by lslater           #+#    #+#             */
/*   Updated: 2024/02/19 14:19:31 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc != 5)
	{
		ft_putstr_fd("invalid num of arguments\n", 2);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (ft_parse(data, argv, envp) == 0)
	{
		ex_command_1(data, data->pid1, envp);
		ex_command_2(data, data->pid2, envp);
		wait(&data->pid1);
		wait(&data->pid2);
	}
    close(data->pipefd[0]);
    close(data->pipefd[1]);
    if (data->infile >= 0)
		close(data->infile);
	if (data->outfile >= 0)
		close(data->outfile);
	ft_free_tab(data->command_1);
	ft_free_tab(data->command_2);
	free(data);
}
