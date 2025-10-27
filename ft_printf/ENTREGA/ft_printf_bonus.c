/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:43:44 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/24 20:53:22 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_and_return_count(va_list args, char const *str)
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
			count += ft_print_count_char(str[i++]);
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

/*int	main(void)
{
	ft_printf("Test: |%10s|\n", "Mariolop");
	ft_printf("Test: |%-10s|\n", "Mariolop");
	ft_printf("Test: |%10.5s|\n", "Mariolop");
	ft_printf("Test: |%10.5s|\n", "Mariolop");
	ft_printf("Test: |%10s|\n", NULL);
	ft_printf("Test: |%-10s|\n", NULL);
	ft_printf("Test: |%10.3s|\n", NULL);
	ft_printf("Test: |%-10.3s|\n", NULL);
	return (0);
}*/
