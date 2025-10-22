/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:45:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/22 10:39:01 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define OK 1
# define KO 0

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

/* Token Struct holding flags status, min-width,
** and precission values.                       */
typedef struct  s_printf_token
{
	int		zero_flag;
	int		minus_flag;
	int		plus_flag;
	int		hash_flag;
	int		space_flag;
	int		min_width;
	int		precision;
	char	specifier;
}			t_printf_token;

/* TOKEN */
int		parse_token(va_list args, const char *str, size_t *i);

/* Main func */
int		ft_printf(const char *str, ...);

/* Chars */
int		ft_print_count_char(char c);
int		ft_print_count_str(char *str);
int		ft_strchr(const char *str, char c);

/* Numbers */
int		ft_putnbr_s(int nbr, const char *base);
int		ft_putnbr_u(unsigned long nbr, const char *base);

/* Pointers */
int		ft_putptr(void *p);
#endif