/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:28:51 by lslater           #+#    #+#             */
/*   Updated: 2024/02/12 15:37:33 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_open(char **files, t_data *data)
{
	data->infile = open(files[1], O_RDONLY);
	data->outfile = open(files[4], O_RDONLY);
	if (data->infile == -1 || data->outfile == -1)
	{
		if (data->infile < 0)
		{
			perror(files[1]);
			close(data->infile);
		}
		if (data->outfile < 0)
		{
			perror(files[4]);
			close(data->outfile);
		}
		return (0);
	}
	return (1);
}

int	find_paths(char **envp, t_data *data)
{
	int		i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (1);
	data->command_paths = ft_split(envp[i] + 5, ':');
	return (0);
}

char	*check_access(char *command, char **envp, t_data *data)
{
	char	*command_with_slash;
	char	*full_path;
	int		i;

	i = 0;
	if(find_paths(envp, data) == 1)
		return (NULL);
	command_with_slash = ft_strjoin("/", command);
	while (data->command_paths && data->command_paths[i])
	{
		full_path = ft_strjoin(data->command_paths[i], command_with_slash);
		if (access(full_path, X_OK) != -1)
		{
			free(full_path);
			free(command_with_slash);
			return (data->command_paths[i]);
		}
		free(full_path);
		i++;
	}
	free(command_with_slash);
	ft_putstr_fd("command not found : ", 2);//to be removed
	ft_putstr_fd(command, 2);//to be removed
	return (0);
}
