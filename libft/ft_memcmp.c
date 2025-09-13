/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:14:36 by mario             #+#    #+#             */
/*   Updated: 2025/08/26 18:23:53 by mario            ###   ########.fr       */
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
