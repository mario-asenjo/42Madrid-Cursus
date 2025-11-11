int	test1()
{
	char	*line1;
	char	*line2;
	
	int fd1 = open("quijote.txt", O_RDONLY);
	int fd2 = open("platero.txt", O_RDONLY);
	while (((line1 = get_next_line(fd1)) != NULL) && ((line2 = get_next_line(fd2)) != NULL))
	{
		printf("IN FD1: %s", line1);
		printf("IN FD2: %s", line2);
		free(line1);
		free(line2);
	}
	close(fd1);
	close(fd2);
	return (1);
}

int	test2()
{
	int fd1 = open("quijote.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	close(fd1);
	printf("%s", get_next_line(fd1));
	return (1);
}

int	main(void)
{
	if (test1())
		printf("El test 1 ha ido bien\n");
	if (test2())
		printf("El test 2 ha terminado.\n");
	return (0);
}

