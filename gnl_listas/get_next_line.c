#include "get_next_line.h"

void	get_new_line_or_eof(int fd, t_list **stash)
{
	char	*buff;
	int	read_bytes;

	while (!ft_lststr_chr(&stash, '\n'))
	{
		buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (!read_bytes)
			return (free(buff));
		buff[read_bytes] = '\0';
		ft_lststr_add_back(&stash, buff);
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
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				line[j++] = list->content[i];
				line[j] = '\0';
				return (line);
			}
			line[j++] = list->content[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
	return (line);
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
	while (*list)
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char		*ret_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ret_line, 0) < 0)
		return (NULL);
	get_new_line_or_eof(fd, &stash);
	if (!stash)
		return (NULL);
	ret_line = retrieve_line(stash);
	reset_list_for_next_call(&stash);
	return (ret_line);
}

