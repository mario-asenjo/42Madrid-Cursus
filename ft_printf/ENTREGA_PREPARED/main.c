#include "ft_printf_bonus.h"
#include <stdio.h>
#include <math.h>

int main()
{
	printf("\n========== TESTS %%f ==========\n");

printf("1. Retorno: %d | %d\n", ft_printf("%f\n", 3.5), printf("%f\n", 3.5));
printf("2. Retorno: %d | %d\n", ft_printf("%f\n", -3.5), printf("%f\n", -3.5));
printf("3. Retorno: %d | %d\n", ft_printf("%+f\n", 42.0), printf("%+f\n", 42.0));
printf("4. Retorno: %d | %d\n", ft_printf("% f\n", 42.0), printf("% f\n", 42.0));

printf("5. Retorno: %d | %d\n", ft_printf("%.0f\n", 12.9), printf("%.0f\n", 12.9));
printf("6. Retorno: %d | %d\n", ft_printf("%.3f\n", 1.23456), printf("%.3f\n", 1.23456));
printf("7. Retorno: %d | %d\n", ft_printf("%.6f\n", -1.23456), printf("%.6f\n", -1.23456));
printf("8. Retorno: %d | %d\n", ft_printf("%#.0f\n", 7.0), printf("%#.0f\n", 7.0));

printf("9. Retorno: %d | %d\n", ft_printf("%10.2f\n", 3.5), printf("%10.2f\n", 3.5));
printf("10. Retorno: %d | %d\n", ft_printf("%-10.2f\n", 3.5), printf("%-10.2f\n", 3.5));
printf("11. Retorno: %d | %d\n", ft_printf("%010.2f\n", 3.5), printf("%010.2f\n", 3.5));
printf("12. Retorno: %d | %d\n", ft_printf("%+010.2f\n", 3.5), printf("%+010.2f\n", 3.5));
printf("13. Retorno: %d | %d\n", ft_printf("% 010.2f\n", 3.5), printf("% 010.2f\n", 3.5));

printf("14. Retorno: %d | %d\n", ft_printf("%.0f\n", 9.5), printf("%.0f\n", 9.5));      // -> 10
printf("15. Retorno: %d | %d\n", ft_printf("%.0f\n", 9.49), printf("%.0f\n", 9.49));    // -> 9
printf("16. Retorno: %d | %d\n", ft_printf("%.2f\n", 9.999), printf("%.2f\n", 9.999));  // -> 10.00
printf("17. Retorno: %d | %d\n", ft_printf("%08.2f\n", 9.999), printf("%08.2f\n", 9.999)); // -> 00010.00

printf("18. Retorno: %d | %d\n", ft_printf("%.0f\n", 123456789.5), printf("%.0f\n", 123456789.5));
printf("19. Retorno: %d | %d\n", ft_printf("%.6f\n", 1.0000004), printf("%.6f\n", 1.0000004));

printf("20. Retorno: %d | %d\n", ft_printf("%-+12.3f\n", 42.125), printf("%-+12.3f\n", 42.125));
printf("21. Retorno: %d | %d\n", ft_printf("% #8.0f\n", 100.0), printf("% #8.0f\n", 100.0));
printf("22. Retorno: %d | %d\n", ft_printf("%#.0f\n", 0.0), printf("%#.0f\n", 0.0));

printf("23. Retorno: %d | %d\n", ft_printf("% .2f\n", -0.0001), printf("% .2f\n", -0.0001));
printf("24. Retorno: %d | %d\n", ft_printf("%+.2f\n", 0.004), printf("%+.2f\n", 0.004));

/* Opcionales: si implementaste NAN e INF */
printf("25. Retorno: %d | %d\n", ft_printf("%f\n", NAN), printf("%f\n", NAN));
printf("26. Retorno: %d | %d\n", ft_printf("%f\n", INFINITY), printf("%f\n", INFINITY));
printf("27. Retorno: %d | %d\n", ft_printf("%f\n", -INFINITY), printf("%f\n", -INFINITY));

	return (0);
}
