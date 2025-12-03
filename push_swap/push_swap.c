/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:55:16 by root              #+#    #+#             */
/*   Updated: 2025/12/02 19:18:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  sort_stack(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sa(a);
    else if (a->size <= 5)
        sort_five(a, b);
    else
        sort_big(a, b);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    if (!parse_args(argc, argv, &a))
        exit_code(&a, NULL, EXIT_FAILURE);
    stack_init(&b, 'b');
    if (stack_is_sorted(&a))
        exit_code(&a, &b, 0);
    sort_stack(&a, &b);
    exit_code(&a, &b, EXIT_SUCCESS);
}
