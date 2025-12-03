/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strutils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:48:38 by masenjo           #+#    #+#             */
/*   Updated: 2025/11/14 20:22:04 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_count_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_count_str(char *str, size_t len)
{
	write(1, str, len);
	return ((int)len);
}

int	ft_iscinstr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (OK);
		i++;
	}
	return (KO);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (OK);
	return (KO);
}
