/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:21:10 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/03 15:45:24 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_max_to_a(t_stack *a, t_stack *b)
{
    int     dist;
    int     max_pos;

    while (b->size > 0)
    {
        max_pos = stack_get_index_max_position(b);
        if (max_pos <= b->size / 2)
        {
            while (max_pos-- > 0)
                rb(b);
        }
        else
        {
            dist = b->size - max_pos;
            while (dist-- > 0)
                rrb(b);   
        }
        pa(a,b);
    }
}

void	sort_big(t_stack *a, t_stack *b)
{
    int chunk_size;
    int range;

    if (!index_stack(a))
        exit_code(a, b, EXIT_FAILURE);
    if (a->size <= 100)
        chunk_size = 20;
    else
        chunk_size = 40;
    range = 0;
    while (a->size > 0)
    {
        if (a->top->index <= range)
        {
            pb(a, b);
            rb(b);
            range++;
        }
        else if (a->top->index <= range + chunk_size)
        {
            pb(a, b);
            range++;
        }
        else
            ra(a);
    }
    push_max_to_a(a, b);
}
