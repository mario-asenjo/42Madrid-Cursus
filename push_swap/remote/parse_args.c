/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:52:48 by root              #+#    #+#             */
/*   Updated: 2025/12/08 07:01:24 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_num(const char *nptr)
{
	int	i;

	if (!nptr || nptr[0] == '\0')
		return (0);
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		i++;
		if (nptr[i] == '-' || nptr[i] == '+' || nptr[i] == '\0')
			return (0);
	}
	while (nptr[i])
	{
		if (!ft_isdigit((unsigned char)nptr[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	convert_str_to_int(const char *str, int *num)
{
	long	atol_ret;

	if (!is_valid_num(str))
		return (0);
	atol_ret = ft_atol(str);
	if (atol_ret < INT_MIN || atol_ret > INT_MAX)
		return (0);
	*num = (int)atol_ret;
	return (1);
}

static int	has_duplicate_numbers(t_stack *stack)
{
	t_node	*out;
	t_node	*in;

	out = stack->top;
	while (out)
	{
		in = out->next;
		while (in)
		{
			if (in->value == out->value)
				return (1);
			in = in->next;
		}
		out = out->next;
	}
	return (0);
}

int	convert_and_insert(t_stack *a, char **splitted)
{
	int		j;
	int		value;
	t_node	*node;

	j = 0;
	while (splitted[j])
	{
		if (!convert_str_to_int(splitted[j], &value))
			return (0);
		node = new_node(value);
		if (!node)
			return (0);
		stack_push_bottom(a, node);
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	**splitted;
	int		i;

	stack_init(a, 'a');
	i = 1 ;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		if (!splitted)
			return (0);
		if (!convert_and_insert(a, splitted))
			return (free_splitted(splitted), 0);
		free_splitted(splitted);
		i++;
	}
	if (!a->top)
		return (0);
	if (has_duplicate_numbers(a))
		return (0);
	return (1);
}
