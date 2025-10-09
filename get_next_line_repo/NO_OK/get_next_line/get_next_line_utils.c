/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:53:07 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/01 19:32:51 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (!src && !dest)
		return (NULL);
	i = 0;
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

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

static char	*ft_strcat(char *dest, const char *src)
{
	int	c_d;
	int	c_s;

	c_d = 0;
	c_s = 0;
	while (dest[c_d] != '\0')
	{
		c_d++;
	}
	while (src[c_s] != '\0')
	{
		dest[c_d] = src[c_s];
		c_s++;
		c_d++;
	}
	dest[c_d] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	str = ft_strcat(str, s2);
	return (str);
}
