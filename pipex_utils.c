/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:28:51 by lslater           #+#    #+#             */
/*   Updated: 2024/02/09 13:01:47 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_paths(char **envp)
{
	char	**command_paths;
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			command_paths = ft_split(envp[i] + 5, ':');
			return (command_paths);
		}
		i++;
	}
	return (NULL);
}

char	*check_access(char *command, char **envp)
{
	char	**command_paths;
	char	*command_with_slash;
	char	*full_path;
	int		i;

	i = 0;
	command_paths = find_paths(envp);
	command_with_slash = ft_strjoin("/", command);
	while (command_paths && command_paths[i])
	{
		full_path = ft_strjoin(command_paths[i], command_with_slash);
		if (access(full_path, X_OK))
			return (command_paths[i]);
		i++;
	}
	return (0);
}
