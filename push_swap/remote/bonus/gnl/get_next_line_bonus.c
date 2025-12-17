/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:26:01 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/09 06:53:53 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
* Stores BUFFER_SIZE null terminated strings holding
* read parts from the file descriptor untill a new
* line character is found in the last node.
*/
void	get_new_line_or_eof(int fd, t_list_gnl **stash)
{
	char	*buff;
	int		read_bytes;

	if (!stash)
		return ;
	while (!ft_lststr_chr(*stash, '\n'))
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (ft_lststr_clear(stash));
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buff);
			if (read_bytes < 0)
				ft_lststr_clear(stash);
			return ;
		}
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
char	*retrieve_line(t_list_gnl *list)
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
		while (list->content && list->content[i])
		{
			line[j++] = list->content[i];
			if (list->content[i++] == '\n')
				return (line[j] = '\0', line);
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
void	finish_reset(t_list_gnl **list, char *buff)
{
	t_list_gnl	*new_node;

	new_node = (t_list_gnl *) malloc(sizeof(t_list_gnl));
	if (!new_node)
		return (free(buff), ft_lststr_clear(list));
	new_node->content = buff;
	new_node->next = NULL;
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

/*
* Resets a list for the next call by searching the
* rest of the string from the '\n' and creating
* a new node in case it's not null, which will become
* the new list.
*/
void	reset_list_for_next_call(t_list_gnl **list)
{
	char		*buff;
	t_list_gnl	*last_node;
	size_t		i;
	size_t		j;

	if (!list || !*list)
		return ;
	last_node = ft_lststr_last(*list);
	i = 0;
	while (last_node->content && last_node->content[i]
		&& last_node->content[i] != '\n')
		i++;
	if (!last_node->content || !last_node->content[i])
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
	static t_list_gnl	*stash[FD_MAX];
	char				*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fcntl(fd, F_GETFD) < 0)
		return (ft_lststr_clear(&stash[fd]), NULL);
	get_new_line_or_eof(fd, &stash[fd]);
	if (!stash[fd])
		return (NULL);
	ret_line = retrieve_line(stash[fd]);
	if (!ret_line)
		return (ft_lststr_clear(&stash[fd]), NULL);
	reset_list_for_next_call(&stash[fd]);
	return (ret_line);
}

/* int	test1()
{
	char	*line1;
	char	*line2;
	
	int fd1 = open("quijote.txt", O_RDONLY);
	int fd2 = open("platero.txt", O_RDONLY);
	while (((line1 = get_next_line(fd1)) != NULL) 
	&& ((line2 = get_next_line(fd2)) != NULL))
	{
		printf("IN FD1: %s", line1);
		printf("IN FD2: %s", line2);
		free(line1);
		free(line2);
	}
	close(fd1);
	close(fd2);
	return (1);
}

int	test2()
{
	int fd1 = open("quijote.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	close(fd1);
	printf("%s", get_next_line(fd1));
	return (1);
}

int	main(void)
{
	if (test1())
		printf("El test 1 ha ido bien\n");
	if (test2())
		printf("El test 2 ha terminado.\n");
	return (0);
}
 */