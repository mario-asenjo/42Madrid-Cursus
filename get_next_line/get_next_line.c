#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long nbl;

	nbl = (long) nb;
	if (nbl / 10 > 0)
		ft_putnbr(nbl / 10);
	ft_putchar(nbl % 10 + '0');
}

char	*get_next_line(int fd)
{
	ft_putnbr(BUFFER_SIZE);	
}

int	main(void)
{
	int	fd1;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 == -1)
		return (ft_perror("Error opening file."), 1);
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("In FD1: %s", line);
		free(line);
	}
	close(fd1);
	return (0);
}
