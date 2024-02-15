/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:06:19 by lslater           #+#    #+#             */
/*   Updated: 2024/02/15 13:40:53 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	create_pipe(pid_t pid)
{
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
		ft_printf("im child = %d\n", getpid());//to be removed
	else
		ft_printf("im parent = %d\n", getpid());//to be removed
	return (0);
}
