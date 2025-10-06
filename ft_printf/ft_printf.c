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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putnbr(int nb)
{
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	char	*s;
	int		d;
	size_t	ind;

	ind = 0;
	va_start(ap, str);
	while (str[ind])
	{
		if (str[ind] == '%' && str[ind + 1] == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
			ind += 2;
		}
		if (str[ind] == '%' && str[ind + 1] == 'd')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
			ind += 2;
		}
		write(1, &str[ind], 1);
		ind++;
	}
	return (1);
}

int	main(void)
{
	if (!ft_printf("%s %s %s %d %s", "hola soy ", "Mario", " tengo ", 12, " años y me gusta todo"))
		return (write(2, "Error.\n", 7), 1);
	return (0);
}
