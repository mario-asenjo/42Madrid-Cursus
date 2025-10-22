/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_token_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:44:57 by mario             #+#    #+#             */
/*   Updated: 2025/10/22 13:07:55 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int init_token(t_printf_token *token)
{
	if (!token)
		return (KO);
	token->zero_flag = 0;
	token->minus_flag = 0;
	token->plus_flag = 0;
	token->hash_flag = 0;
	token->space_flag = 0;
	token->min_width = 0;
	token->precision = -1;
	token->specifier = '\0';
	return (OK);
}

static void    handle_flags(t_printf_token *token, const char *str, size_t *i)
{
	while (ft_strchr("-+ 0#", str[*i]))
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

static void	handle_width(t_printf_token *token, va_list args, char const *str, size_t *i)
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
	while (ft_strchr("0123456789", str[*i]))
	{
			token->min_width = token->min_width * 10 + (str[*i] - '0');
			(*i)++;
	}
}

static void	handle_precision(t_printf_token *token, va_list args, char const *str, size_t *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		token->precision = 0;
	}
}

int	parse_token(va_list args, const char *str, size_t *i)
{
	size_t			count;
	t_printf_token	token;

	if (!str || !i)
		return (KO);
	if (!init_token(&token))
		return (0);
	count = 0;
	handle_flags(&token, str, i);
	//DEBUG PARSEO FLAGS
	printf("FLAGS: zero=%d minus=%d plus=%d space=%d hash=%d | i=%zu\n",
	   token.zero_flag, token.minus_flag, token.plus_flag,
	   token.space_flag, token.hash_flag, *i);
	handle_width(&token, args, str, i);
	handle_precision(&token, args, str, i);
	   return (count);
}