/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:15:41 by mario             #+#    #+#             */
/*   Updated: 2025/10/27 18:47:59 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
/**/

int	ulong_to_dec(unsigned long n, char *buff, const char *base)
{
	int		len;
	int		base_len;
	int		i;
	char	temp;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (n == 0)
		buff[len++] = base[0];
	while (n > 0)
	{
		buff[len++] = base[n % base_len];
		n /= base_len;
	}
	i = 0;
	while (i < len / 2)
	{
		temp = buff[i];
		buff[i] = buff[len - 1 - i];
		buff[len - 1 - i++] = temp;
	}
	buff[len] = '\0';
	return (len);
}

int	ft_print_n_char(char c, int times)
{
	int	count;

	count = 0;
	while (times--)
		count += ft_print_count_char(c);
	return (count);
}
