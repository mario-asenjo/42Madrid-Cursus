/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:15:41 by mario             #+#    #+#             */
/*   Updated: 2025/10/24 11:09:42 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int	uint_to_dec(unsigned int n, char *buff, const char *base)
{
	int	len;
	int	base_len;
	int	i;
	char temp;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (n == 0)
		buff[len++] = base[0];
	while (n)
	{
		buff[len++] = base[n % base_len];
		n /= base_len;
	}
	i = 0;
	while (i < len / 2)
	{
		temp = buff[i];
		buff[i] = buff[len - 1 - i];
		buff[len - 1 - i] = temp;
	}
	buff[len] = '\0';
	return (len);
}

int	ft_print_n_char(char c, int times)
{
	int count;

	count = 0;
	while (times--)
            count += ft_print_count_char(c);
	return (count);
}

void	init_data_to_print(t_printf_data *data, t_printf_token *token, int nbr, char *base)
{
	data->sign = 0;
	data->sign_len = 0;
	data->magnitude = (unsigned int)nbr;
	if (nbr < 0)
	{
		data->sign = '-';
		data->magnitude = (unsigned int) (-(long)nbr);
	}
	else if (token->plus_flag)
		data->sign = '+';
	else if (token->space_flag)
		data->sign = ' ';
	if (data->sign)
		data->sign_len = 1;
	data->num_len = uint_to_dec(data->magnitude, data->num_buff, base);
	if (token->precision == 0 && data->magnitude == 0)
		data->num_len = 0;
	data->zero_prec = 0;
	if (token->precision > data->num_len)
		data->zero_prec = token->precision - data->num_len;
	data->content_len = data->sign_len + ft_max(data->num_len + data->zero_prec, 0);
	data->padding = token->min_width - data->content_len;
	if (data->padding < 0)
		data->padding = 0;
}
