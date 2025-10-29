/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:06:06 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/29 19:11:54 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

/* libc = printf("%.09s", NULL);
	printf("\n");
	mine = ft_printf("%.09s", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("%3.6s", NULL);
	printf("\n");
	mine = ft_printf("%3.6s", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("%20.6s", NULL);
	printf("\n");
	mine = ft_printf("%20.6s", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("%-3.8s", NULL);
	printf("\n");
	mine = ft_printf("%-3.8s", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("%-10.8s", NULL);
	printf("\n");
	mine = ft_printf("%-10.8s", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);
 */

	/* libc = printf("%117p%-44c%-156c%-88.109s%0%" ,
		(void*)8225290685743754462lu,-123,65,NULL);
	printf("\n");
	mine = ft_printf("%117p%-44c%-156c%-88.109s%0%" ,
		(void*)8225290685743754462lu,-123,65,NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("%0168.128u%0054.92x%30.171s" ,2620195206u,1771128939u,NULL);
	printf("\n");
	mine = ft_printf("%0168.128u%0054.92x%30.171s" ,
		2620195206u,1771128939u,NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine); */

	/* libc = printf("%15p\n", NULL);
	printf("\n");
	mine = ft_printf("%15p\n", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("%-15p\n", NULL);
	printf("\n");
	mine = ft_printf("%-15p\n", NULL);
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine); */

	/* libc = printf("percent 2 %12%");
	printf("\n");
	mine = ft_printf("percent 2 %12%");
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);

	libc = printf("percent 3 %-12%");
	printf("\n");
	mine = ft_printf("percent 3 %-12%");
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);
 */

int	main(void)
{
	int	mine;
	int	libc;

	libc = printf("%5%");
	printf("\n");
	mine = ft_printf("%5%");
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);
	libc = printf("%-5%");
	printf("\n");
	mine = ft_printf("%-5%");
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);
	libc = printf("%-05%");
	printf("\n");
	mine = ft_printf("%-05%");
	printf("\n");
	printf("Count libc: %d | Count mine: %d\n", libc, mine);
	return (0);
}
