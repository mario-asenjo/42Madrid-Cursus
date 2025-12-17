/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:45:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/09/29 15:52:28 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbl;
	char	*repr;

	len = ft_numlen(n);
	repr = (char *) malloc(sizeof(char) * (len + 1));
	if (!repr)
		return (NULL);
	repr[len] = '\0';
	nbl = n;
	if (nbl < 0)
	{
		repr[0] = '-';
		nbl *= -1;
	}
	if (nbl == 0)
		repr[0] = '0';
	while (nbl > 0)
	{
		repr[--len] = nbl % 10 + '0';
		nbl /= 10;
	}
	return (repr);
}
