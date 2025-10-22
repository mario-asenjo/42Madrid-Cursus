/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:33:10 by mario             #+#    #+#             */
/*   Updated: 2025/10/22 13:54:18 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void    handle_flags(t_printf_token *token, const char *str, size_t *i)
{
	while (ft_iscinstr("-+ 0#", str[*i]))
	{
		if (str[*i] == '0' && !token->zero_flag)
			token->zero_flag = 1;
		if (str[*i] == '-')
			token->minus_flag = 1;
		if (str[*i] == '+')
			token->plus_flag = 1;
		if (str[*i] == ' ')
			token->space_flag = 1;
		if (str[*i] == '#')
			token->hash_flag = 1;
		(*i)++;
	}
}

void	handle_width(t_printf_token *token, va_list args, char const *str, size_t *i)
{
	if (str[*i] == '*')
	{
		token->min_width = va_arg(args, int);
		(*i)++;
		if (token->min_width < 0)
		{
			token->minus_flag = 1;
			token->min_width *= -1;
		}
	}
	while (ft_isdigit(str[*i]))
	{
			token->min_width = token->min_width * 10 + (str[*i] - '0');
			(*i)++;
	}
}

void	handle_precision(t_printf_token *token, va_list args, char const *str, size_t *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		token->precision = 0;
		if (str[*i] == '*')
		{
			token->precision = va_arg(args, int);
			(*i)++;
			if (token->precision < 0)
				token->precision = -1;
		}
		else
		{
			while (ft_isdigit(str[*i]))
			{
				token->precision = token->precision * 10 + (str[*i] - '0');
				(*i)++;
			}
		}
	}
}

void	handle_specifier(t_printf_token *token, char const *str, size_t *i)
{
	if (ft_iscinstr("cspiduxX%", str[*i]))
	{
		token->specifier = str[*i];
		(*i)++;
	}
}
