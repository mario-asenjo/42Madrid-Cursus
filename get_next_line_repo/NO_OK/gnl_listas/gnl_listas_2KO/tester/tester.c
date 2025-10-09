/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:42:40 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 20:00:48 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** Test runner para get_next_line
** Incluye detección de leaks con valgrind (via Makefile)
*/
extern void	set_malloc_fail_after(int n);

void	run_test(const char *filename)
{
	//set_malloc_fail_after(4);
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return;
	}
	printf("\n=== TEST: %s ===\n", filename);
	char *line;
	int i = 1;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[line %d] %s", i++, line);
		free(line);
	}
	printf("(EOF)\n");
	close(fd);
}

void	run_all_tests(void)
{
	size_t		i;

	const char 	*tests[] = {
		"tests/test_empty.txt",
		"tests/test_short.txt",
		"tests/test_long.txt",
		"tests/test_no_newline.txt",
		"tests/test_multiline.txt",
		"tests/test_big.txt",
		"tests/test_binary.bin",
		"tests/test_newlines_only.txt",
		NULL
	};
    i = 0;
	while (tests[i])
		run_test(tests[i++]);
}

int	main(void)
{
	printf(">>> Starting get_next_line tests...\n");
	run_all_tests();
	printf("\n>>> All tests completed.\n");
	return (0);
}
