/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:59:51 by masenjo           #+#    #+#             */
/*   Updated: 2025/08/25 22:02:53 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*addr;

	if (number && size > SIZE_MAX / number)
		return (0);
	addr = malloc(size * number);
	if (!addr)
		return (0);
	ft_bzero(addr, size * number);
	return (addr);
}
