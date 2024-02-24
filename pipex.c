/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:38:48 by lslater           #+#    #+#             */
/*   Updated: 2024/02/24 11:57:59 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		i;

	i = 2;
	if (argc != 5)
	{
		ft_printf("%i\n", argc);
		ft_putstr_fd("invalid num of arguments\n", 2);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->path_error = 0;
	if (ft_parse(data, argv, envp) == 0)
	{
		data->argv = argv;
		ex_command_1(data, &(data->pid[0]), envp);
		ex_command_2(data, &(data->pid[1]), envp);
		close_fds(data);
		while (i)
			waitpid(data->pid[--i], NULL, 0);
	}
	ft_free_tab(data->command_1);
	ft_free_tab(data->command_2);
	free(data);
}
