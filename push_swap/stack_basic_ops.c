/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:12:49 by root              #+#    #+#             */
/*   Updated: 2025/12/02 15:31:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_push_top(t_stack *stack, t_node *node)
{
    if (!node)
        return ;
    node->prev = NULL;
    node->next = stack->top;
    if (stack->top != NULL)
        stack->top->prev = node;
    stack->top = node;
    if (stack->bottom == NULL)
        stack->bottom = node;
    stack->size++;
}

t_node  *stack_pop_top(t_stack *stack)
{
    t_node  *node;
    
    if (stack->top == NULL)
        return (NULL);
    node = stack->top;
    stack->top = node->next;
    if (stack->top != NULL)
        stack->top->prev = NULL;
    else
        stack->bottom = NULL;
    node->next = NULL;
    node->prev = NULL;
    stack->size--;
    return (node);
}

void    stack_push_bottom(t_stack *stack, t_node *node)
{
    if (!node)
        return ;
    node->next = NULL;
    node->prev = stack->bottom;
    if (stack->bottom != NULL)
        stack->bottom->next = node;
    stack->bottom = node;
    if (stack->top == NULL)
        stack->top = node;
    stack->size++;
}
