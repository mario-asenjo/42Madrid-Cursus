/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:23:47 by root              #+#    #+#             */
/*   Updated: 2025/12/02 18:35:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *a)
{
    op_swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    op_swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
    op_swap(a);
    op_swap(b);
    write(1, "ss\n", 3);
}