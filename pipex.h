/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:49:14 by lslater           #+#    #+#             */
/*   Updated: 2024/02/12 15:26:06 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


typedef struct s_data
{
	int		infile;
	int		outfile;
	char	*command;
	char	**command_paths;
} t_data;
int		find_paths(char **envp,t_data *data);
char	*check_access(char *command, char **envp, t_data *data);
int		ft_open(char **files, t_data *data);

#endif