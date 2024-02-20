/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:48:59 by lslater           #+#    #+#             */
/*   Updated: 2024/02/20 13:59:16 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_paths(char *command_with_slash, char **command_paths)
{
	free(command_with_slash);
	ft_free_tab(command_paths);
}

void	close_fds(t_data *data)
{
	if (data->pipefd[0] > 2)
		close(data->pipefd[0]);
	if (data->pipefd[1] > 2)
		close(data->pipefd[1]);
	if (data->infile > 2)
		close(data->infile);
	if (data->outfile > 2)
		close(data->outfile);
}
