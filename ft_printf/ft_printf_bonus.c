/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:43:44 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/22 13:38:34 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*int	parse(va_list args, const char *str, size_t i)
{
	size_t	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_count_char(va_arg(args, int));
	else if (str[i] == '%')
		count += ft_print_count_char('%');
	else if (str[i] == 's')
		count += ft_print_count_str(va_arg(args, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr_s(va_arg(args, int), "0123456789");
	else if (str[i] == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned long), "0123456789");
	else if (str[i] == 'x')
		count += ft_putnbr_u(va_arg(args, unsigned long), "0123456789abcdef");
	else if (str[i] == 'X')
		count += ft_putnbr_u(va_arg(args, unsigned long), "0123456789ABCDEF");
	else if (str[i] == 'p')
		count += ft_putptr(va_arg(args, void *));
	return (count);
}*/

int	print_and_return_count(va_list args, char const *str)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			count += parse_token(args, str, &i);
		}
		else
			count += ft_print_count_char(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		count;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = print_and_return_count(ap, str);
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	int	count_mine = 0;
	int count_printf = 0;
	int a = -42;
	unsigned int ua = (unsigned int) a;
	void *p = &a;

	count_printf = printf("LIBC: |%d| %i |%u| %x %X |%p| %s |%c|\n",
			a, a, ua, 255U, 255U, p, "hola!", 'c');
	count_mine = ft_printf("MINE: |%d| %i |%u| %x %X |%p| %s |%c|\n",
			a, a, ua, 255U, 255U, p, "hola!", 'c');
	ft_printf("count_printf: %d\n", count_printf);
	ft_printf("count_mine: %d\n", count_mine);
	ft_printf("Test: |%-+ 0#d|\n", 42);
	return (0);
}
*/