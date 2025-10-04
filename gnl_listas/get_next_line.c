/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:01:13 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/03 21:17:24 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_new_line_or_eof(int fd, t_list **stash)
{
	char	*buff;
	int		read_bytes;

	while (!ft_lststr_chr(*stash, '\n'))
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (!read_bytes)
			return (free(buff));
		buff[read_bytes] = '\0';
		ft_lststr_add_back(stash, buff);
	}
}

char	*retrieve_line(t_list *list)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*line;

	len = ft_lststr_count_till_nl(list);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				line[j++] = list->content[i];
				return (line[j] = '\0', line);
			}
			line[j++] = list->content[i++];
		}
		list = list->next;
	}
	return (line[j] = '\0', line);
}

void	finish_reset(t_list **list, t_list *new_node, char *buff)
{
	ft_lststr_clear(list);
	if (buff[0] == '\0')
	{
		free(buff);
		free(new_node);
		*list = NULL;
	}
	else
		*list = new_node;
}

void	reset_list_for_next_call(t_list **list)
{
	t_list	*new_node;
	char	*buff;
	t_list	*last_node;
	size_t	i;
	size_t	j;

	new_node = (t_list *)malloc(sizeof(t_list));
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_node || !buff)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content[i] == '\n')
		i++;
	while (last_node->content[i])
		buff[j++] = last_node->content[i++];
	buff[j] = '\0';
	new_node->content = buff;
	new_node->next = NULL;
	finish_reset(list, new_node, buff);
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ret_line, 0) < 0)
		return (NULL);
	get_new_line_or_eof(fd, &stash);
	if (!stash)
		return (NULL);
	ret_line = retrieve_line(stash);
	reset_list_for_next_call(&stash);
	return (ret_line);
}
