/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:45:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/09/29 11:49:15 by masenjo          ###   ########.fr       */
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
