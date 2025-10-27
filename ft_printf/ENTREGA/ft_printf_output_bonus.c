/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:25:45 by mario             #+#    #+#             */
/*   Updated: 2025/10/24 22:35:26 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	print_token_char(t_printf_token *token, int c)
{
	size_t	count;
	int		padding;

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

size_t	print_token_str(t_printf_token *token, char *str)
{
	size_t	slen;
	int		padding;
	size_t	count;

	if (!str)
		str = "(null)";
	slen = ft_strlen(str, token);
	if (token->precision >= 0 && (int)slen > token->precision)
		slen = token->precision;
	padding = (int)token->min_width - (int)slen;
	if (padding < 0)
		padding = 0;
	count = 0;
	if (token->minus_flag)
		count += ft_print_count_str(str, slen)
			+ ft_print_n_char(' ', padding);
	else
		count += ft_print_n_char(' ', padding)
			+ ft_print_count_str(str, slen);
	return (count);
}

size_t	print_token_sint(t_printf_token *token, int nbr, const char *base)
{
	t_printf_data	data;

	if (!ft_check_base(base))
		return (0);
	init_data_to_print_s(&data, token, nbr, base);
	return (ft_print_number_with_flags(token, &data));
}

size_t	print_token_uint(t_printf_token *token,
		unsigned int n, const char *base)
{
	t_printf_data	data;

	if (!ft_check_base(base))
		return (0);
	init_data_to_print_u(&data, token, n, base);
	return (ft_print_number_with_flags(token, &data));
}

size_t	print_token_ptr(t_printf_token *token, void *p,
			const char *base)
{
	t_printf_data	data;

	if (!p)
		return (ft_print_count_str("(nil)", 5));
	if (!ft_check_base(base))
		return (0);
	init_data_to_print_ptr(&data, token, p, base);
	return (ft_print_number_with_flags(token, &data));
}
