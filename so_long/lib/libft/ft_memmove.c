/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:45:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/09/29 11:52:30 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(unsigned char *p_dest, const unsigned char *p_src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
}

static void	ft_rcpy(unsigned char *p_dest, const unsigned char *p_src, size_t n)
{
	while (n > 0)
	{
		n--;
		p_dest[n] = p_src[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (dest == src)
		return (dest);
	if (dest < src)
		ft_copy(p_dest, p_src, n);
	else
		ft_rcpy(p_dest, p_src, n);
	return (dest);
}
