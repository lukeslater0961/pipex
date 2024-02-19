/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:54:46 by lslater           #+#    #+#             */
/*   Updated: 2024/02/19 10:09:29 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_files(char **argv, t_data *data)
{
	if (ft_open(argv, data) == 1)
		return (1);
	return (0);
}

int	ft_parse(t_data *data, char **argv, char **envp)
{
	data->command_1 = ft_split(argv[2], ' ');
	data->command_2 = ft_split(argv[3], ' ');
	data->argv = argv;
	if (check_files(argv, data) == 1)
		return (1);
	check_access(data->command_1, envp);
	check_access(data->command_2, envp);
	ft_printf(" command 1 path = %s\n", *data->command_1);//to be removed
	ft_printf(" command 2 path = %s\n", *data->command_2);//to be removed
	return (0);
}
