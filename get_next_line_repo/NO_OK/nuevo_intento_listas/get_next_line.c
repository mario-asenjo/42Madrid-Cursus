/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:41:34 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 17:01:59 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Función que rellena stash con nodos que tienen
* contenido del fichero hasta que en uno de ellos
* haya un '\n' todos con tamaño BUFFER_SIZE + 1
*/
int	fill_till_nl(int fd, t_list **stash)
{
	char	*buff;
	int		read_bytes;

	while (!ft_lststr_chr(*stash, '\n'))
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (KO);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buff), KO);
		if (read_bytes == 0)
		{
			free(buff);
			break ;
		}
		buff[read_bytes] = '\0';
		if (!ft_lststr_add_back(stash, buff))
			return (KO);
	}
	if (!stash)
		return (KO);
	return (OK);
}

/*
* Función que devuelve una línea hasta un '\n' en caso de haberlo
* y en caso de no haberlo, una línea hasta el final que se haya
* leído (EOF)
*/
char	*retrieve_line(t_list *stash)
{
	char	*ret_line;
	int		len_till_nl;
	t_list	*aux;
	int		l_c;
	int		s_c;

	len_till_nl = ft_lststr_count_till_nl(stash);
	if (len_till_nl <= 0)
		return (NULL);
	ret_line = (char *) malloc(sizeof(char) * len_till_nl + 1);
	if (!ret_line)
		return (NULL);
	l_c = 0;
	aux = stash;
	while (aux && l_c < len_till_nl)
	{
		s_c = 0;
		while (aux->content[s_c] && l_c < len_till_nl)
			ret_line[l_c++] = aux->content[s_c++];
		aux = aux->next;
	}
	ret_line[l_c] = '\0';
	return (ret_line);
}

/*
* Función que crea un nodo con rest, y despues de liberar
* stash, lo setea a este nuevo nodo. a menos que el content sea
* null, que la lista quedará nula.
*/
int	clean_and_reset_stash(t_list **stash, char *rest)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (free(rest), KO);
	ft_lststr_clear(stash);
	if (!rest)
	{
		free(new_node);
		free(rest);
		*stash = NULL;
	}
	else
	{
		new_node->content = rest;
		new_node->next = NULL;
		*stash = new_node;
	}
	return (1);
}

/*
* Función que busca el ultimo nodo (el que tiene /n)
* Copia en rest desde el \n hasta el final del content.
* LLama a clean and reset stash para resetear el stash
* con el content de rest.
*/
int	reset_list_for_next_call(t_list **stash)
{
	t_list	*node_with_nl;
	char	*rest;
	size_t	len;
	size_t	i;

	node_with_nl = ft_lstlast(*stash);
	if (!node_with_nl)
		return (KO);
	len = 0;
	rest = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!rest)
		return (free(node_with_nl), KO);
	while (node_with_nl->content[len] && node_with_nl->content[len] != '\n')
		len++;
	i = 0;
	while (node_with_nl->content[len] && node_with_nl->content[++len])
		rest[i] = node_with_nl->content[len];
	rest[i] = '\0';
	if (!clean_and_reset_stash(stash, rest))
		return (free(node_with_nl), free(rest), KO);
	return (free(node_with_nl), OK);
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) <= 0)
		return (NULL);
	if (!fill_till_nl(fd, &stash))
		return (ft_lststr_clear(&stash), NULL);
	ret_line = retrieve_line(stash);
	if (!ret_line)
		return (ft_lststr_clear(&stash), NULL);
	if (!reset_list_for_next_call(&stash))
		return (free(ret_line), ft_lststr_clear(&stash), NULL);
	return (ret_line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/