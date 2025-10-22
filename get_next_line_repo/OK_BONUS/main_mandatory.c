int	main(void)
{
	char	*line;
	int fd = open("quijote.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("IN FD: %s", line);
		free(line);
	}
	close(fd);
}

