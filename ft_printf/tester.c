/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:43:17 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/27 19:00:21 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	int				mine;
	int				libc;
	unsigned int	u;
	unsigned int	huge;
	void			*p;
	void			*np;
	int				clib, cft;

	u = 255;
	huge = 4294967295;
	p = &u;
	np = NULL;
	printf("\n===== TESTS %%c =====\n");

	libc = printf("LIBC: |%c|\n", 'A');
	mine = ft_printf("MINE: |%c|\n", 'A');
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%5c|\n", 'B');
	mine = ft_printf("MINE: |%5c|\n", 'B');
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-5c|\n", 'C');
	mine = ft_printf("MINE: |%-5c|\n", 'C');
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%c %c %c|\n", 'A', 'B', 'C');
	mine = ft_printf("MINE: |%c %c %c|\n", 'A', 'B', 'C');
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	printf("\n===== TESTS %%s =====\n");
	
	libc = printf("LIBC: |%s|\n", "Hello");
	mine = ft_printf("MINE: |%s|\n", "Hello");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%10s|\n", "Hello");
	mine = ft_printf("MINE: |%10s|\n", "Hello");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-10s|\n", "Hello");
	mine = ft_printf("MINE: |%-10s|\n", "Hello");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%.3s|\n", "Hello");
	mine = ft_printf("MINE: |%.3s|\n", "Hello");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%10.3s|\n", "Hello");
	mine = ft_printf("MINE: |%10.3s|\n", "Hello");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-10.3s|\n", "Hello");
	mine = ft_printf("MINE: |%-10.3s|\n", "Hello");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	printf("\n===== TESTS %%s with NULL =====\n");
	
	libc = printf("LIBC: |%s|\n", NULL);
	mine = ft_printf("MINE: |%s|\n", NULL);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%10s|\n", NULL);
	mine = ft_printf("MINE: |%10s|\n", NULL);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%.3s|\n", NULL);
	mine = ft_printf("MINE: |%.3s|\n", NULL);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-10.3s|\n", NULL);
	mine = ft_printf("MINE: |%-10.3s|\n", NULL);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	printf("\n===== MIXED TESTS =====\n");
	
	libc = printf("LIBC: |%c| and |%s|\n", 'Z', "42Madrid");
	mine = ft_printf("MINE: |%c| and |%s|\n", 'Z', "42Madrid");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%5c| %-10s |%.4s|\n", 'Q', "World", "abcdef");
	mine = ft_printf("MINE: |%5c| %-10s |%.4s|\n", 'Q', "World", "abcdef");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	printf("\n===== TESTS %%d / %%i =====\n");
	
	libc = printf("LIBC: |%d|\n", 42);
	mine = ft_printf("MINE: |%d|\n", 42);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%i|\n", -42);
	mine = ft_printf("MINE: |%i|\n", -42);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%10d|\n", 123);
	mine = ft_printf("MINE: |%10d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-10d|\n", 123);
	mine = ft_printf("MINE: |%-10d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%010d|\n", 123);
	mine = ft_printf("MINE: |%010d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%+10d|\n", 123);
	mine = ft_printf("MINE: |%+10d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%+10d|\n", -123);
	mine = ft_printf("MINE: |%+10d|\n", -123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |% 10d|\n", 123);
	mine = ft_printf("MINE: |% 10d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%.5d|\n", 123);
	mine = ft_printf("MINE: |%.5d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%10.5d|\n", 123);
	mine = ft_printf("MINE: |%10.5d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-10.5d|\n", 123);
	mine = ft_printf("MINE: |%-10.5d|\n", 123);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%.0d|\n", 0);
	mine = ft_printf("MINE: |%.0d|\n", 0);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%10.0d|\n", 0);
	mine = ft_printf("MINE: |%10.0d|\n", 0);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%-10.0d|\n", 0);
	mine = ft_printf("MINE: |%-10.0d|\n", 0);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("LIBC: |%+d % d %i %i|\n", 42, 42, -42, 0);
	mine = ft_printf("MINE: |%+d % d %i %i|\n", 42, 42, -42, 0);
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	printf("\n========== TEST %%u ==========\n");
	clib = printf("|%u|\n", u);
	cft = ft_printf("|%u|\n", u);
	printf("count_libc=%d | count_ft=%d\n\n", clib, cft);

	printf("Zero padding width (10):\n");
	printf("|%010u|\n", u);
	ft_printf("|%010u|\n", u);
	printf("Left align width (10):\n");
	printf("|%-10u|\n", u);
	ft_printf("|%-10u|\n", u);
	printf("Precision only (8):\n");
	printf("|%.8u|\n", u);
	ft_printf("|%.8u|\n", u);
	printf("Width+Precision (12.8):\n");
	printf("|%12.8u|\n", u);
	ft_printf("|%12.8u|\n", u);
	printf("Zero value with precision 0 (should print nothing):\n");
	printf("|%.0u|\n", 0);
	ft_printf("|%.0u|\n", 0);
	printf("Huge number (max unsigned int):\n");
	printf("|%u|\n", huge);
	ft_printf("|%u|\n", huge);

	printf("\n========== TEST %%x / %%X ==========\n");
	printf("Lowercase / Uppercase:\n");
	printf("|%x| |%X|\n", u, u);
	ft_printf("|%x| |%X|\n", u, u);

	printf("Zero-padded width (10):\n");
	printf("|%010x| |%010X|\n", u, u);
	ft_printf("|%010x| |%010X|\n", u, u);

	printf("Width + precision (12.8):\n");
	printf("|%12.8x| |%12.8X|\n", u, u);
	ft_printf("|%12.8x| |%12.8X|\n", u, u);

	printf("Hash flag (#):\n");
	printf("|%#x| |%#X|\n", u, u);
	ft_printf("|%#x| |%#X|\n", u, u);

	printf("Hash flag + zero width:\n");
	printf("|%#010x| |%#010X|\n", u, u);
	ft_printf("|%#010x| |%#010X|\n", u, u);

	printf("Zero value with # (no prefix expected):\n");
	printf("|%#x| |%#X|\n", 0, 0);
	ft_printf("|%#x| |%#X|\n", 0, 0);

	printf("\n========== TEST %%p ==========\n");
	printf("Pointer normal:\n");
	printf("|%p|\n", p);
	ft_printf("|%p|\n", p);

	printf("Pointer NULL:\n");
	printf("|%p|\n", np);
	ft_printf("|%p|\n", np);

	printf("Width (20):\n");
	printf("|%20p|\n", p);
	ft_printf("|%20p|\n", p);

	printf("Left align (width 20):\n");
	printf("|%-20p|\n", p);
	ft_printf("|%-20p|\n", p);

	printf("Zero flag (ignored):\n");
	printf("|%020p|\n", p);
	ft_printf("|%020p|\n", p);

	printf("\n======= TEST %%s erroneos ========\n");
	libc = printf("%5%");
	printf("\n");
	mine = ft_printf("%5%");
	printf("\n");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	libc = printf("%-5%");
	printf("\n");
	mine = ft_printf("%-5%");
	printf("\n");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);

	libc = printf("%-05%");
	printf("|\n");
	mine = ft_printf("%-05%");
	printf("|\n");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);

	libc = printf("%.03s", NULL);
	printf("|\n");
	mine = ft_printf("%.03s", NULL);
	printf("|\n");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);

	libc = printf("%3.1s", NULL);
	printf("|\n");
	mine = ft_printf("%3.1s", NULL);
	printf("|\n");
	printf("count libc: %d | count mine: %d\n\n", libc, mine);
	
	printf("\n========== END OF TESTS ==========\n");
	return (0);
}
