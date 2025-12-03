/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:29:43 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/03 15:01:10 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_get_min_position(t_stack *stack)
{
    t_node  *curr;
    int     min_val;
    int     min_pos;
    int     pos;

    curr = stack->top;
    min_val = curr->value;
    pos = 0;
    min_pos = 0;
    while (curr->next)
    {
        pos++;
        curr = curr ->next;
        if (curr->value < min_val)
        {
            min_val = curr->value;
            min_pos = pos;
        }
    }
    return min_pos;
}

int stack_get_index_max_position(t_stack *stack)
{
    t_node  *curr;
    int     max_index;
    int     max_pos;
    int     pos;

    curr = stack->top;
    max_index = curr->index;
    max_pos = 0;
    pos = 0;
    while (curr)
    {
        if (curr->index > max_index)
        {
            max_index = curr->index;
            max_pos = pos;
        }
        curr = curr->next;
        pos++;
    }
    return (max_pos);
}
