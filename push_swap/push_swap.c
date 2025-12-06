/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:55:16 by root              #+#    #+#             */
/*   Updated: 2025/12/06 09:38:40 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_stack(t_stack *a, t_stack *b)
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
        exit_code(NULL, NULL, ERROR_ARGS);
    if (!parse_args(argc, argv, &a))
        exit_code(&a, NULL, ERROR_PARSING);
    stack_init(&b, 'b');
    if (stack_is_sorted(&a))
        exit_code(&a, &b, ALREADY_SORED);
    sort_stack(&a, &b);
    exit_code(&a, &b, EXIT_SUCCESS);
}
