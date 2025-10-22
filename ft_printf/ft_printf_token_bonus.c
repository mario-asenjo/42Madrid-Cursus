/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_token_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:44:57 by mario             #+#    #+#             */
/*   Updated: 2025/10/22 18:30:19 by mario            ###   ########.fr       */
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

size_t	print_token(t_printf_token *token, va_list args)
{
	size_t count;

	count = 0;
	if (token->specifier == 'c')
		count += print_token_char(token, va_arg(args, int));
	if (token->specifier == '%')
		count += print_token_char(token, '%');
	if (token->specifier == 's')
		count += print_token_str(token, va_arg(args, char *));
	if (token->specifier == 'i' || token->specifier == 'd')
		count += print_token_sint(token, va_arg(args, int), "0123456789");
	if (token->specifier == 'u')
		count += print_token_uint(token, va_arg(args, unsigned int), "0123456789");
	if (token->specifier == 'x')
		count += print_token_uint(token, va_arg(args, unsigned int), "0123456789abcdef");
	if (token->specifier == 'X')
		count += print_token_uint(token, va_arg(args, unsigned int), "0123456789ABCDEF");
	if (token->specifier == 'p')
		count += print_token_ptr(token, va_arg(args, void *));
	return (count);
}

/*DEBUG PARSEO FLAGS
	printf("FLAGS: zero=%d minus=%d plus=%d space=%d hash=%d | i=%zu\n",
	   token.zero_flag, token.minus_flag, token.plus_flag,
	   token.space_flag, token.hash_flag, *i);
	handle_width(&token, args, str, i);
*/
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
	handle_width(&token, args, str, i);
	handle_precision(&token, args, str, i);
	handle_specifier(&token, str, i);
	count += print_token(&token, args);
	return (count);
}
