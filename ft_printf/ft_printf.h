/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:45:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/10 21:40:12 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef long long			t_ll;
typedef unsigned long long	t_ull;

/* Main func */
int		ft_printf(const char *str, ...);

/* Chars */
int		ft_print_count_char(char c);
int		ft_print_count_str(char *str);
/* Numbers */
int		ft_putnbr_s(long long nbr, const char *base);
int		ft_putnbr_u(unsigned long long nbr, const char *base);
/* Pointers */
int		ft_putptr(void *p);
#endif