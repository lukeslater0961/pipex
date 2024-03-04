/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:38:48 by lslater           #+#    #+#             */
/*   Updated: 2024/03/03 16:57:49 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(t_data *data, char **envp, char **argv)
{
	int		i;

	i = 2;
	if (ft_parse(data, argv, envp) == 0)
	{
		data->argv = argv;
		if (pipe(data->pipefd) == -1)
		{
			perror("./pipex");
			exit (EXIT_FAILURE);
		}
		if (data->infile != -1)
			setup_command_1(data, &(data->pid[0]), envp); 
		if (data->outfile != -1)
			setup_command_2(data, &(data->pid[1]), envp);
		close_fds(data, 1);
		if (data->infile != -1)
			waitpid(data->pid[0], NULL, 0);
		if (data->outfile != -1)
			waitpid(data->pid[1], NULL, 0);
	}
}

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
	pipex_start(data, envp, argv);
	close_fds(data, 0);
	ft_free_tab(data->command_1);
	ft_free_tab(data->command_2);
	free(data);
}
