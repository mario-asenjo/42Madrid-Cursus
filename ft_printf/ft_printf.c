/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:43:44 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/06 21:39:52 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_and_return_count(va_list args, char const *str)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				count += ft_print_count_char(va_arg(args, int));
			else if (str[i] == 's')
				count += ft_print_count_str(va_arg(args, char *));
			else if (str[i] == 'd')
				count += ft_print_count_nbr(va_arg(args, int), "0123456789");
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

int	main(void)
{
	int	count_mine = 0;
	int count_printf = 0;
	if (!ft_printf("%s %s!, tienes %d años?", "Hola", "Juan", 18))
		return (write(2, "Error.\n", 7), 1);
	count_printf = printf("Hola %s %d!", "Mario", -22);
	count_mine = ft_printf("Hola %s %d!", "Mario", -22);
	printf("count_printf: %d", count_printf);
	printf("count_mine: %d", count_mine);
	return (0);
}
