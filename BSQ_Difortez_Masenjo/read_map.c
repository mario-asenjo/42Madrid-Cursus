/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:04:51 by difortez          #+#    #+#             */
/*   Updated: 2025/07/30 18:08:51 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

ssize_t	size_file(char *map)
{
	int		fd;
	char	buffer[1];
	ssize_t	bytes;
	ssize_t	total_bytes;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	total_bytes = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 1);
		if (bytes == 0)
			break ;
		if (bytes == -1)
			return (0);
		total_bytes += bytes;
	}
	close(fd);
	return (total_bytes);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*buff;
	ssize_t	len;
	ssize_t	read_bytes;

	len = size_file(filename);
	if (len <= 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = (char *)malloc(len + 1);
	if (!buff)
		return (0);
	read_bytes = read(fd, buff, len);
	if (read_bytes <= 0)
	{
		close(fd);
		return (0);
	}
	buff[len] = '\0';
	return (buff);
}

void	get_header_line(char *input_data, char *header)
{
	int	i;

	i = 0;
	while (input_data[i] && input_data[i] != '\n' && i < 99)
	{
		header[i] = input_data[i];
		i++;
	}
	header[i] = '\0';
}

int	parse_header(char *line, t_legend *info)
{
	int		len;
	char	num[11];
	int		i;

	len = 0;
	while (line[len])
		len++;
	if (len < 4)
		return (0);
	info->solver_c = line[len - 1];
	info->obstacle_c = line[len - 2];
	info->empty_c = line[len - 3];
	if (!valid_legend(info))
		return (0);
	if (len - 3 > 11)
		return (0);
	i = 0;
	while (i < len - 3)
	{
		num[i] = line[i];
		i++;
	}
	num[len - 3] = '\0';
	info->size = ft_atoi(num);
	return (info->size > 0);
}

t_legend	*init_legend(char *input_data, char *header)
{
	t_legend	*info;

	info = (t_legend *)malloc(sizeof(t_legend));
	if (!info)
	{
		free(info);
		ft_errors("map error\n");
	}
	get_header_line(input_data, header);
	if (!parse_header(header, info))
	{
		free(info);
		ft_errors("map error\n");
	}
	return (info);
}
