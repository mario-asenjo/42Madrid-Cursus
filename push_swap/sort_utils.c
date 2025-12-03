/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:29:43 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/03 11:55:27 by masenjo          ###   ########.fr       */
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
