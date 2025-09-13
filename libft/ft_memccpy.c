/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:14:19 by mario             #+#    #+#             */
/*   Updated: 2025/09/12 16:43:03 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	i = 0;
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		if (p_src[i] == (unsigned char)c)
			return (p_dest + i + 1);
		i++;
	}
	return (0);
}
