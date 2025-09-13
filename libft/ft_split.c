/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:33:52 by mario             #+#    #+#             */
/*   Updated: 2025/09/13 15:27:49 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char c)
{
	int		i;
	int		flag;
	size_t	wc;

	wc = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && !flag)
		{
			wc++;
			flag = 1;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (wc);
}

static void	ft_advance(char const *s, size_t *i, size_t *begin, char c)
{
	while (s[*i] == c)
		(*i)++;
	*begin = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
}

static char	*ft_newstrcpy(char const *src, size_t begin, size_t end)
{
	char	*ret;
	size_t	len;

	len = end - begin;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &src[begin], len + 1);
	return (ret);
}

void	ft_free(char **arr, size_t pos)
{
	while (pos > 0)
	{
		pos--;
		free(arr[pos]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	begin;
	size_t	pos;
	size_t	wc;

	wc = ft_count_words(s, c);
	arr = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[i])
	{
		ft_advance(s, &i, &begin, c);
		if (begin < i)
		{
			arr[pos] = ft_newstrcpy(s, begin, i);
			if (!arr[pos])
				return (ft_free(arr, pos), NULL);
			pos++;
		}
	}
	arr[pos] = NULL;
	return (arr);
}
