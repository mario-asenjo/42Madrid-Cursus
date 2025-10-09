/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:58:16 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 20:24:33 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

// Gestión de listas
void	ft_lstclear(t_list **lst);
int		ft_lststr_chr(t_list *lst, char c);
void	ft_lststr_add_back(t_list **lst, char *content);
void	ft_lststr_clear(t_list **lst);
size_t	ft_lststr_count_till_nl(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

// Función principal
char	*get_next_line(int fd);
void	get_new_line_or_eof(int fd, t_list **stash);
char	*retrieve_line(t_list *list);
void	reset_list_for_next_call(t_list **list);

#endif
