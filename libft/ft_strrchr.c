/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:16:36 by mario             #+#    #+#             */
/*   Updated: 2025/08/25 22:27:50 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[l]);
	while (l > 0)
	{
		if (s[l - 1] == (char)c)
			return ((char *)&s[l - 1]);
		l--;
	}
	return (0);
}
