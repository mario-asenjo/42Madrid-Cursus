/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numutils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:19:43 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/24 10:08:24 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(const char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((unsigned char) base[i] < 32 || (unsigned char) base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_u(unsigned long nbr, const char *base)
{
	unsigned int		base_size;
	char				nbr_final[100];
	int					i;
	int					count;

	if (!check_base(base))
		return (0);
	base_size = 0;
	while (base[base_size])
		base_size++;
	i = 0;
	if (nbr == 0)
		return (ft_print_count_char(base[0]));
	while (nbr)
	{
		nbr_final[i++] = base[nbr % base_size];
		nbr = nbr / base_size;
	}
	count = 0;
	while (--i >= 0)
		count += ft_print_count_char(nbr_final[i]);
	return (count);
}

int	ft_putnbr_s(int n, const char *base)
{
	int					count;
	unsigned int		nbr;

	count = 0;
	if (n < 0)
	{
		count += ft_print_count_char('-');
		nbr = (unsigned long)-n;
	}
	else
		nbr = (unsigned long)n;
	count += ft_putnbr_u(nbr, base);
	return (count);
}

int	ft_putptr(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_print_count_str("(nil)"));
	count += ft_print_count_str("0x");
	count += ft_putnbr_u((unsigned long)p, "0123456789abcdef");
	return (count);
}
