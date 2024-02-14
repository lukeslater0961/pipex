/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:38:48 by lslater           #+#    #+#             */
/*   Updated: 2024/02/14 13:42:49 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc != 5)
	{
		ft_putstr_fd("invalid num of arguments", 2);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_parse(data, argv, envp);
	ft_free_tab(data->command_1);
	ft_free_tab(data->command_2);
	// free(data->full_path);
	free(data);
}
