/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 06:48:33 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/09 15:05:39 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_string(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isalpha(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_op(char *op)
{
	if ((ft_strcmp(op, "sa") == 0)
		|| (ft_strcmp(op, "sb") == 0)
		|| (ft_strcmp(op, "ss") == 0)
		|| (ft_strcmp(op, "pa") == 0)
		|| (ft_strcmp(op, "pb") == 0)
		|| (ft_strcmp(op, "ra") == 0)
		|| (ft_strcmp(op, "rb") == 0)
		|| (ft_strcmp(op, "rr") == 0)
		|| (ft_strcmp(op, "rra") == 0)
		|| (ft_strcmp(op, "rrb") == 0)
		|| (ft_strcmp(op, "rrr") == 0))
		return (1);
	else
		return (0);
}

int	read_standard_input(t_list_gnl **ops)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!is_string(line))
			return (0);
		if (!is_valid_op(line))
			return (0);
		ft_lststr_add_back(ops, line);
		line = get_next_line(0);
	}
	return (1);
}

static void	rot_operations(t_stack *a, t_stack *b, t_list_gnl *ops)
{
	if (ft_strcmp(ops->content, "ra") == 0)
		op_rotate(a);
	else if (ft_strcmp(ops->content, "rb") == 0)
		op_rotate(b);
	else if (ft_strcmp(ops->content, "rr") == 0)
	{
		op_rotate(a);
		op_rotate(b);
	}
	else if (ft_strcmp(ops->content, "rra") == 0)
		op_rev_rotate(a);
	else if (ft_strcmp(ops->content, "rrb") == 0)
		op_rev_rotate(b);
	else if (ft_strcmp(ops->content, "rrr") == 0)
	{
		op_rev_rotate(a);
		op_rev_rotate(b);
	}
}

void	efectuate_operations(t_stack *a, t_stack *b, t_list_gnl *ops)
{
	while (ops)
	{
		if (ft_strcmp(ops->content, "sa") == 0)
			op_swap(a);
		else if (ft_strcmp(ops->content, "sb") == 0)
			op_swap(b);
		else if (ft_strcmp(ops->content, "ss") == 0)
		{
			op_swap(a);
			op_swap(b);
		}
		else if (ft_strcmp(ops->content, "pa") == 0)
			op_push(b, a);
		else if (ft_strcmp(ops->content, "pb") == 0)
			op_push(a, b);
		rot_operations(a, b, ops);
		ops = ops->next;
	}
}
