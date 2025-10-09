/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:26:01 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 20:35:54 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
* Stores BUFFER_SIZE null terminated strings holding
* read parts from the file descriptor untill a new
* line character is found in the last node.
*/
void	get_new_line_or_eof(int fd, t_list **stash)
{
	char	*buff;
	int		read_bytes;

	while (!ft_lststr_chr(*stash, '\n'))
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (ft_lststr_clear(stash));
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (free(buff));
		buff[read_bytes] = '\0';
		ft_lststr_add_back(stash, buff);
	}
}

/*
* Looks for the new line character in the list
* and retrieves a char * holding from the begining
* untill the new line character included.
* @returns A new line with the '\n' or not if EOF.
*/
char	*retrieve_line(t_list *list)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*line;

	len = ft_lststr_count_till_nl(list);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line || len == 0)
		return (free(line), NULL);
	j = 0;
	while (list)
	{
		if (!list->content)
			break ;
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (line[j++] = list->content[i], line[j] = '\0', line);
			line[j++] = list->content[i++];
		}
		list = list->next;
	}
	return (line[j] = '\0', line);
}

/*
* Finishes the process of reset_list_for_next_call()
* by creating the new node ,setting it's content and
* setting the list for the next call.
*/
void	finish_reset(t_list **list, char *buff)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (free(buff), ft_lststr_clear(list));
	new_node->content = buff;
	new_node->next = NULL;
	ft_lststr_clear(list);
	*list = new_node;
}

/*
* Resets a list for the next call by searching the
* rest of the string from the '\n' and creating
* a new node in case it's not null, which will become
* the new list.
*/
void	reset_list_for_next_call(t_list **list)
{
	char	*buff;
	t_list	*last_node;
	size_t	i;
	size_t	j;

	if (!list || !*list)
		return ;
	last_node = ft_lstlast(*list);
	if (!last_node || !last_node->content)
		return (ft_lststr_clear(list));
	i = 0;
	while (last_node->content && last_node->content[i]
		&& last_node->content[i] != '\n')
		i++;
	if (!last_node->content || !last_node->content[i]
		|| !last_node->content[i + 1])
		return (ft_lststr_clear(list));
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_lststr_clear(list));
	j = 0;
	while (last_node->content && last_node->content[++i])
		buff[j++] = last_node->content[i];
	buff[j] = '\0';
	finish_reset(list, buff);
}

/*
* Function that reads a whole line from a file descriptor
* @returns The line read with the '\n' at the end.
*/
char	*get_next_line(int fd)
{
	static t_list	*stash[FD_MAX];
	char			*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_new_line_or_eof(fd, &stash[fd]);
	if (!stash[fd])
		return (NULL);
	ret_line = retrieve_line(stash[fd]);
	if (!ret_line)
		return (NULL);
	reset_list_for_next_call(&stash[fd]);
	return (ret_line);
}
