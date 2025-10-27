#include <stdio.h>
#include "ft_printf_bonus.h"

int main(void)
{
	int	mine;
	int	libc;
	
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
}
