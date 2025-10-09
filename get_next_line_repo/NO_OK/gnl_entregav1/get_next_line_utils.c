/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:22:00 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 20:24:30 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Finds a char inside a list which content is char *
* @returns if c Is in list -> 1 else -> 0
*/
int	ft_lststr_chr(t_list *lst, char c)
{
	size_t	i;
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		if (!aux->content)
			return (0);
		i = 0;
		while (aux->content[i])
		{
			if (aux->content[i] == c)
				return (1);
			i++;
		}
		aux = aux->next;
	}
	return (0);
}

/*
* Creates a new node with the content provided and
* adds it at the end of the list.
*/
void	ft_lststr_add_back(t_list **lst, char *content)
{
	t_list	*aux;
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (free(content));
	new->content = content;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

/*
* Cleans the list and sets it to null.
*/
void	ft_lststr_clear(t_list **lst)
{
	t_list	*aux;
	t_list	*temp;

	if (!lst || !(*lst))
		return ;
	aux = (*lst);
	temp = aux;
	while (temp != NULL)
	{
		temp = temp->next;
		if (aux->content)
			free(aux->content);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}

/*
* Counts how many chars till new line inside list
* new line included.
*/
size_t	ft_lststr_count_till_nl(t_list *list)
{
	size_t	len;
	size_t	i;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		if (!list->content)
			return (len);
		i = 0;
		while (list->content[i])
		{
			len++;
			if (list->content[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

/*
* Retrieves the last node of a list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
