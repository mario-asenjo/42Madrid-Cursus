/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:53:58 by root              #+#    #+#             */
/*   Updated: 2025/12/08 08:35:58 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus/push_swap_bonus.h"

void	exit_code(t_stack *a, t_stack *b, int code)
{
	if (a)
		stack_clear(a);
	if (b)
		stack_clear(b);
	if (code == ERROR_ARGS || code == ERROR_PARSING
		|| code == STDIN_READ_ERROR)
		write(2, "Error\n", 6);
	exit(code);
}
