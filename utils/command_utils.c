/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:28:51 by lslater           #+#    #+#             */
/*   Updated: 2024/03/02 16:27:07 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_open(char **files, t_data *data)
{
	data->infile = open(files[1], O_RDONLY);
	data->outfile = open(files[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
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

int	access_loop(char **cmd_path, char *full_path, char *full_cmd,
	char **cmd)
{
	int	i;

	i = 0;
	if (*cmd && !access(*cmd, X_OK))
	{
		free_paths(full_cmd, cmd_path, NULL);
		free(full_path);
		return (0);
	}
	else
	{
		while (cmd_path && cmd_path[++i])
		{
			full_path = ft_strjoin(cmd_path[i], full_cmd);
			if (full_path && !access(full_path, X_OK))
			{
				free_paths(full_cmd, cmd_path, cmd);
				*cmd = full_path;
				return (0);
			}
			free(full_path);
		}
	}
	free_paths(full_cmd, cmd_path, NULL);
	return (1);
}

int	check_access(char **command, char **envp)
{
	char	*full_path;
	char	*command_with_slash;
	char	**command_paths;

	command_paths = find_paths(envp);
	command_with_slash = ft_strjoin("/", *command);
	full_path = NULL;
	if (ft_strlen(*cmd_path) == 0)
	{
		free_paths(command_with_slash, command_paths, NULL);
		free(full_path);
		return (1);
	}
	if (access_loop(command_paths, full_path, command_with_slash, command) == 1)
		return (1);
	return (0);
}
