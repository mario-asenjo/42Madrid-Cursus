/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:01:13 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/04 23:28:11 by masenjo          ###   ########.fr       */
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
			return (ft_lststr_clear(stash));
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
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
	if (!line || len == 0)
		return (free(line), NULL);
	j = 0;
	while (list)
	{
		if (!list->content)
			break;
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
	while (last_node->content && last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (!last_node->content || !last_node->content[i] || !last_node->content[i + 1])
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

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_new_line_or_eof(fd, &stash);
	if (!stash)
		return (NULL);
	ret_line = retrieve_line(stash);
	if (!ret_line)
		return (NULL);
	reset_list_for_next_call(&stash);
	return (ret_line);
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
}*/
