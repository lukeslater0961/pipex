/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:04:51 by lslater           #+#    #+#             */
/*   Updated: 2024/02/19 11:10:26 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}
