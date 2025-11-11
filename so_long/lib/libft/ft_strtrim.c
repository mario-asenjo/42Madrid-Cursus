/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:45:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/09/29 11:48:59 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stralloc(size_t len)
{
	char	*str;

	str = (char *) malloc(sizeof(char ) * len + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, len + 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	begin;
	size_t	end;

	if (!s1 || !set)
		return (ft_stralloc(0));
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	new = ft_stralloc(end - begin);
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[begin], end - begin + 1);
	return (new);
}
