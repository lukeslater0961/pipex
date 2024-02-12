/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:38:48 by lslater           #+#    #+#             */
/*   Updated: 2024/02/12 15:49:27 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_data	*data;
	(void)argv;
	(void)envp;
	if (argc != 5)
	{
		ft_putstr_fd("invalid num of arguments", 2);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	//add parsing function to deal with paths , files etc and split the commands if theres a flag ex (cat -e);
	check_access("cat", envp, data);
	ft_free_tab(data->command_paths);
	check_access("hello", envp, data);
	ft_free_tab(data->command_paths);
	free(data);
}
