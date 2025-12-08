/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:27:16 by masenjo           #+#    #+#             */
/*   Updated: 2025/12/08 08:25:52 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}						t_list_gnl;

// Gestión de listas
int		ft_lststr_chr(t_list_gnl *lst, char c);
void	ft_lststr_add_back(t_list_gnl **lst, char *content);
void	ft_lststr_clear(t_list_gnl **lst);
size_t	ft_lststr_count_till_nl(t_list_gnl *lst);
t_list_gnl	*ft_lststr_last(t_list_gnl *lst);

// Función principal
char	*get_next_line(int fd);
void	get_new_line_or_eof(int fd, t_list_gnl **stash);
char	*retrieve_line(t_list_gnl *list);
void	reset_list_for_next_call(t_list_gnl **list);

#endif
