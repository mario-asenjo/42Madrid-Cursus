/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:55:12 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/02 16:16:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    t_stack a;
    t_node *n1 = new_node(1);
    t_node *n2 = new_node(2);
    t_node *n3 = new_node(3);

    stack_init(&a, 'a');
    stack_push_top(&a, n3);
    stack_push_top(&a, n2);
    stack_push_top(&a, n1);

    op_swap(&a);
    t_node *curr = a.top;
    while (curr != NULL)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
    stack_clear(&a);
    return (0);
}
