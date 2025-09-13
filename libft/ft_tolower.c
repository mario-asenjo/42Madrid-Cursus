/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:17:05 by mario             #+#    #+#             */
/*   Updated: 2025/09/12 15:17:03 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if ((unsigned int) c >= 65 && (unsigned int) c <= 90)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper((char)c))
		return (c + 32);
	return (c);
}
