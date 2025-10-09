/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:45:15 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/06 20:57:24 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void    ft_putchar(char c);
int     ft_print_count_char(char c);
int     ft_print_count_str(char *str);
int     ft_print_count_nbr(int nbr, char *base);

#endif