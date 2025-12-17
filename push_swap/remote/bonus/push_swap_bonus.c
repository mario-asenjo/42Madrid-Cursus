/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:08:04 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/09 06:52:38 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_list_gnl	*operations;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &a))
		exit_code(&a, NULL, ERROR_PARSING);
	stack_init(&b, 'b');
	operations = NULL;
	if (!read_standard_input(&operations))
	{
		ft_lststr_clear(&operations);
		exit_code(&a, &b, STDIN_READ_ERROR);
	}
	efectuate_operations(&a, &b, operations);
	ft_lststr_clear(&operations);
	if (stack_is_sorted(&a) && b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
