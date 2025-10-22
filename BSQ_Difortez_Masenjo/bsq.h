/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:50 by difortez          #+#    #+#             */
/*   Updated: 2025/07/30 18:22:16 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define STD_BUFF_SIZE 4194304

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_legend
{
	int		size;
	int		cols;
	char	empty_c;
	char	obstacle_c;
	char	solver_c;
}	t_legend;

// CHECKER
int			valid_legend(t_legend *legend);
int			check_columns(char **map, int len);
int			parse_data(char **map, t_legend *info);
int			check_line_count(char *input_data, int size);

// SOLVE_BSQ
int			**assign_values(char **map, int **matrix, t_legend *legend);
int			**init_matrix(char **map, t_legend *legend);
int			find_bsq(char **map, int **map_matrix, t_legend *legend);
void		print_bsq(char **map, int *max_square, t_legend *legend);
void		solve_bsq(char **map, t_legend *legend);

// IO UTILS 1
void		ft_errors(char *str);
int			ft_atoi(char *str);
int			ft_min(int **matrix, int i, int j);
void		free_matrix(int **matrix, int n);
void		free_map(char **matrix, int n);

// IO UTILS 2
ssize_t		size_file(char *map);
char		*read_file(char *filename);
void		get_header_line(char *input_data, char *header);
int			parse_header(char *line, t_legend *info);
t_legend	*init_legend(char *input_data, char *header);

// IO UTILS 3
void		process_std_in(void);
int			fill_map_line(char **map, char *input_data, int *i, int *k);
char		**ft_splitlines(char *input_data,
				int start, int rows, t_legend *info);
int			count_columns(char *line);
void		process_map(char *input_data);

#endif