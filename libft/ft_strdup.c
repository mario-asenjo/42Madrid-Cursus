/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:15:28 by mario             #+#    #+#             */
/*   Updated: 2025/08/26 18:21:30 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	l;
	char	*new;

	l = ft_strlen(str);
	new = (char *) malloc(sizeof(char) * (l + 1));
	if (!new)
		return (0);
	ft_memcpy(new, str, l);
	new[l] = '\0';
	return (new);
}
