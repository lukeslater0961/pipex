/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:28:51 by lslater           #+#    #+#             */
/*   Updated: 2024/02/15 14:12:04 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// int	ex_commands(t_data *data)
// {
// 	if(create_pipe(data->pid1) == 1)
// 		return (1);
// 	return (0);
// }

int	ft_open(char **files, t_data *data)
{
	data->infile = open(files[1], O_RDONLY);
	data->outfile = open(files[4], O_CREAT | O_RDWR);
	if (data->infile == -1 || data->outfile == -1)
	{
		if (data->infile < 0)
			perror(files[1]);
		if (data->outfile < 0)
			perror(files[4]);
		return (1);
	}
	return (0);
}

char	**find_paths(char **envp)
{
	int		i;
	char	**command_paths;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	command_paths = ft_split(envp[i] + 5, ':');
	return (command_paths);
}

int	check_access(char *command, char **envp, t_data *data)
{
	char	*command_with_slash;
	char	**command_paths;
	int		i;

	i = 0;
	command_paths = find_paths(envp);
	if (*command_paths == NULL)
		return (1);
	command_with_slash = ft_strjoin("/", command);
	while (command_paths && command_paths[i])
	{
		data->full_path = ft_strjoin(command_paths[i], command_with_slash);
		if (access(data->full_path, X_OK) != -1)
		{
			free_paths(command_with_slash, command_paths);
			ft_printf("\nfull path = %s\n", data->full_path);// to be removed
			return (0);
		}
		if (!(command_paths[i]))
			free(data->full_path);
		i++;
	}
	free_paths(command_with_slash, command_paths);
	ft_putstr_fd("command not found :", 2);
	ft_putstr_fd(command, 2);
	ft_printf("\nfull path = %s\n", data->full_path);// to be removed
	return (1);
}
