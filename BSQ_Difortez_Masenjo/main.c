/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:40:05 by difortez          #+#    #+#             */
/*   Updated: 2025/07/29 21:29:25 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	char	*input_map;
	int		i;

	if (ac == 1)
		process_std_in();
	else
	{
		i = 1;
		while (i < ac)
		{
			input_map = read_file(av[i]);
			process_map(input_map);
			write(1, "\n", 1);
			free(input_map);
			i++;
		}
	}
	return (0);
}
