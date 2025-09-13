/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:17:09 by mario             #+#    #+#             */
/*   Updated: 2025/09/12 15:16:06 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if ((unsigned int) c >= 97 && (unsigned int) c <= 122)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower((char)c))
		return (c - 32);
	return (c);
}
