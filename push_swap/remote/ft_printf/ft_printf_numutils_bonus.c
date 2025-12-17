/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numutils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:19:43 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/24 20:34:35 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check_base(const char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!base || !base[0] || !base[1])
		return (KO);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (KO);
		if ((unsigned char) base[i] < 32 || (unsigned char) base[i] > 126)
			return (KO);
		while (base[z])
		{
			if (base[i] == base[z])
				return (KO);
			z++;
		}
		i++;
	}
	return (OK);
}

size_t	ft_print_number_with_flags(t_printf_token *token,
			t_printf_data *data)
{
	size_t	count;
	char	pad_char;

	count = 0;
	pad_char = ' ';
	if (token->zero_flag && token->precision < 0 && !token->minus_flag)
		pad_char = '0';
	if (token->minus_flag)
		count += ft_print_count_str(data->sign, data->sign_len)
			+ ft_print_n_char('0', data->zero_prec)
			+ write(1, data->num_buff, data->num_len)
			+ ft_print_n_char(pad_char, data->padding);
	else
	{
		if (pad_char == '0')
			count += ft_print_count_str(data->sign, data->sign_len)
				+ ft_print_n_char(pad_char, data->padding);
		else
			count += ft_print_n_char(pad_char, data->padding)
				+ft_print_count_str(data->sign, data->sign_len);
		count += ft_print_n_char('0', data->zero_prec)
			+ write(1, data->num_buff, data->num_len);
	}
	return (count);
}
