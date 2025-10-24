/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:25:45 by mario             #+#    #+#             */
/*   Updated: 2025/10/24 16:32:38 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t  print_token_char(t_printf_token * token, int c)
{
	size_t  count;
	int     padding;

	count = 0;
	padding = token->min_width - 1;
	if (padding < 0)
		padding = 0;
	if (token->minus_flag)
	{
		count += ft_print_count_char(c);
		count += ft_print_n_char(' ', padding);
	}
	else
	{
		count += ft_print_n_char(' ', padding);
		count += ft_print_count_char(c);
	}
	return (count);
}

size_t  print_token_str(t_printf_token *token, char *str)
{
	size_t  len;
	size_t  count;
	int     padding;
	
	len = ft_strlen(str);
	if (token->precision >= 0 && (int)len > token->precision)
		len = token->precision;
	padding = (int)token->min_width - (int)len;
	if (padding < 0)
		padding = 0;
	count = 0;
	if (token->minus_flag)
	{
		count += ft_print_count_str(str, len);
		count += ft_print_n_char(' ', padding);
	}
	else
	{
		count += ft_print_n_char(' ', padding);
		count += ft_print_count_str(str, len);
	}
	return (count);
}

size_t  print_token_sint(t_printf_token *token, int nbr, const char *base)
{
	t_printf_data data;
	
	init_data_to_print(&data, token, nbr, base);
	return (print_signed_with_flags(token, &data));
}
