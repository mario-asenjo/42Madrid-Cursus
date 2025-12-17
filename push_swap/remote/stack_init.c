/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:43:57 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/06 13:41:18 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stack_init(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack->top;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack_init(stack, stack->name);
}
