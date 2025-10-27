/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:48:03 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/27 18:48:14 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_data_numeric(t_printf_data *data,
			t_printf_token *token, const char *base)
{
	data->num_len = ulong_to_dec(data->magnitude, data->num_buff, base);
	if (token->precision == 0 && data->magnitude == 0)
		data->num_len = 0;
	data->zero_prec = 0;
	if (token->precision > data->num_len)
		data->zero_prec = token->precision - data->num_len;
	data->content_len = data->sign_len
		+ ft_max(data->num_len + data->zero_prec, 0);
	data->padding = token->min_width - data->content_len;
	if (data->padding < 0)
		data->padding = 0;
}

void	init_data_to_print_s(t_printf_data *data,
			t_printf_token *token, int nbr, const char *base)
{
	data->sign[0] = '\0';
	data->sign[1] = '\0';
	data->sign_len = 0;
	data->magnitude = (unsigned int)nbr;
	if (nbr < 0)
	{
		data->sign[0] = '-';
		data->magnitude = (unsigned int)(-(long)nbr);
	}
	else if (token->plus_flag)
		data->sign[0] = '+';
	else if (token->space_flag)
		data->sign[0] = ' ';
	if (data->sign[0])
		data->sign_len = 1;
	init_data_numeric(data, token, base);
}

void	init_data_to_print_u(t_printf_data *data,
			t_printf_token *token, unsigned int n, const char *base)
{
	data->sign_len = 0;
	data->sign[2] = '\0';
	data->magnitude = n;
	if (token->hash_flag && n != 0
		&& (base[10] == 'a' || base[10] == 'A'))
	{
		data->sign[0] = '0';
		if (base[10] == 'a')
			data->sign[1] = 'x';
		else
			data->sign[1] = 'X';
		data->sign_len = 2;
	}
	init_data_numeric(data, token, base);
}

void	init_data_to_print_ptr(t_printf_data *data,
		t_printf_token *token, void *p, const char *base)
{
	data->sign[0] = '0';
	data->sign[1] = 'x';
	data->sign[2] = '\0';
	data->sign_len = 2;
	data->magnitude = (unsigned long) p;
	init_data_numeric(data, token, base);
}
