/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:53:58 by root              #+#    #+#             */
/*   Updated: 2025/12/02 19:01:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    exit_code(t_stack *a, t_stack *b, int code)
{
    if (a)
        stack_clear(a);
    if (b)
        stack_clear(b);
    if (code == EXIT_FAILURE)
        write(2, "Error\n", 6);
    exit(code);
}

