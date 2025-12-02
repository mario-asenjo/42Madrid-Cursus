/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:45:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/09/29 11:52:41 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char const	*p_s1;
	unsigned char const	*p_s2;
	size_t				i;

	i = 0;
	p_s1 = (unsigned char const *)s1;
	p_s2 = (unsigned char const *)s2;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
			return ((int)p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}
