/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:53:22 by masenjo           #+#    #+#             */
/*   Updated: 2025/09/30 19:16:47 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	ssize_t		read_bytes;

	if (ft_strchr(buff, '\n'))
		return ("Estoy en salto de linea en buff");
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes < 0)
		return ("Error leyendo el fichero con read.");
	if (!read_bytes)
		return ("Como es 0 devuelvo el resto.");
	if (ft_strlen(buff) < 1)
		return ("Longitud de buff menor que 1.");
	return (NULL);
}

int	main(void)
{
	int		fd1;
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
