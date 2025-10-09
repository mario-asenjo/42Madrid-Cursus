/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:25:06 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 16:53:38 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Función que cuenta cuantos carácteres hay
* hasta que encuentra un salto de línea,
* este incluido
*/
int	ft_lststr_count_till_nl(t_list *list)
{
	size_t	len;
	size_t	i;

	if (!list || ft_lststr_chr(list, '\n'))
		return (-1);
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
* Función que libera toda la lista y su contenido, dejandola nula.
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
* Función que comprueba si un caracter está en una lista
* de strings (char *) como contenido de cada nodo
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
				return (OK);
			i++;
		}
		aux = aux->next;
	}
	return (KO);
}

/*
* Función que crea un nodo con el content (malloc(3))
* y lo añade al final del stash
*/
int	ft_lststr_add_back(t_list **stash, char *content)
{
	t_list	*aux;
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (free(content), KO);
	new->content = content;
	new->next = NULL;
	if (!(*stash))
		*stash = new;
	else
	{
		aux = *stash;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
	return (OK);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
