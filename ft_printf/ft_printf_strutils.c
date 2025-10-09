#include "ft_printf.h"

int	ft_print_count_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_count_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}