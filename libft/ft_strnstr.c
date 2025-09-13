/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:16:32 by mario             #+#    #+#             */
/*   Updated: 2025/09/03 13:31:27 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	if (*little == '\0')
		return ((char *)big);
	if (!big && len == 0)
		return (NULL);
	i = 0;
	l_len = ft_strlen(little);
	while (big[i] && (i + l_len) <= len)
	{
		if (!ft_strncmp(&big[i], little, l_len))
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
