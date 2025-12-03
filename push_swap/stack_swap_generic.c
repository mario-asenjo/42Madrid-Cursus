/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_generic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:31:15 by root              #+#    #+#             */
/*   Updated: 2025/12/03 11:38:38 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    op_swap(t_stack *stack)
{
    t_node  *first;
    t_node  *second;

    if (stack->size < 2)
        return ;
    first = stack->top;
    second = first->next;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->top = second;
    if (stack->bottom == second)
        stack->bottom = first;
}

void    op_push(t_stack *from, t_stack *to)
{
    t_node  *node;

    node = stack_pop_top(from);
    if (!node)
        return ;
    stack_push_top(to, node);
}

void    op_rotate(t_stack *stack)
{
    t_node  *node;

    if (stack->size < 2)
        return ;
    node = stack_pop_top(stack);
    stack_push_bottom(stack, node);
}

void    op_rev_rotate(t_stack *stack)
{
    t_node  *node;

    if (stack->size < 2)
        return ;
    node = stack->bottom;
    stack->bottom = node->prev;
    stack->bottom->next = NULL;
    node->prev = NULL;
    node->next = stack->top;
    stack->top->prev = node;
    stack->top = node;
}
