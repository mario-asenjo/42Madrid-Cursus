/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:53:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/01 21:37:02 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}

static char	*aux_get_line(char *buff, int fd)
{
	char	*temp_buff;
	ssize_t	read_bytes;
	char	*joined;

	while (!ft_strchr(buff, '\n'))
	{
		temp_buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_bytes = read(fd, temp_buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(temp_buff);
			break ;
		}
		if (!read_bytes)
		{
			free(temp_buff);
			break ;
		}
		temp_buff[read_bytes] = '\0';
		joined = ft_strjoin(buff, temp_buff);
		free(temp_buff);
		free(buff);
		buff = joined;
	}
	return (buff);
}

static char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*rest;
	int			position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	buff = aux_get_line(buff, fd);
	if (!buff || !*buff)
		return (free(buff), buff = NULL, NULL);
	position = ft_index_of(buff, '\n');
	if (position > 0)
	{
		line = ft_substr(buff, 0, position + 1);
		rest = ft_substr(buff, position + 1, ft_strlen(buff) - position - 1);
	}
	else
	{
		line = ft_strdup(buff);
		rest = ft_strdup("");
	}
	return (free(buff), buff = rest, line);
}

/*int	main(void)
{
	int		fd1;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 == -1)
		return (printf("Error opening file."), 1);
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("In FD1: %s", line);
		free(line);
	}
	close(fd1);
	return (0);
}*/
