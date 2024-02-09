/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:03 by lslater           #+#    #+#             */
/*   Updated: 2024/02/07 09:50:22 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbrhex(unsigned int n, char *base);
int	ft_putnbr(long long n);
int	ft_test_p(void *n, char *base);
int	ft_putnbrhex_p(unsigned long int n, char *base);
#endif