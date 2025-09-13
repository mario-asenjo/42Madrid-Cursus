/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:04:17 by mario             #+#    #+#             */
/*   Updated: 2025/09/13 00:10:27 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;

	nbl = (long) n;
	if (nbl < 0)
	{
		write(fd, "-", 1);
		nbl *= -1;
	}
	if (nbl / 10 > 0)
		ft_putnbr_fd(nbl / 10, fd);
	ft_putchar_fd(nbl % 10 + '0', fd);
}
