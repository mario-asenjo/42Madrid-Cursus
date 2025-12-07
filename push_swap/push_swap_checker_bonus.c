/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:08:04 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/05 11:11:15 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        exit_code(NULL, NULL, EXIT_FAILURE);
    if (!parse_args(argc, argv, &a))
        exit_code(&a, NULL, EXIT_FAILURE);
    stack_init(&b, 'b');
    return (0);
}