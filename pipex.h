/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:49:14 by lslater           #+#    #+#             */
/*   Updated: 2024/02/14 18:52:32 by lslater          ###   ########.fr       */
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
	char	**command_1;
	char	**command_2;
	char	*full_path;
} t_data;
char	**find_paths(char **envp);
int		check_access(char *command, char **envp, t_data *data);
int		ft_open(char **files, t_data *data);
int		ft_parse(t_data *data, char **argv, char **envp);
void    free_paths(char *command_with_slash, char **command_paths);

#endif