/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:18:26 by root              #+#    #+#             */
/*   Updated: 2025/12/02 19:26:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

static void    sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

    first = a->top->value;
    second = a->top->next->value;
    third = a->bottom->value;
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}
