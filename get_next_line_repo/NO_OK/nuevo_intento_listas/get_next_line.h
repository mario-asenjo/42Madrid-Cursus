/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:44:30 by masenjo           #+#    #+#             */
/*   Updated: 2025/10/05 16:20:52 by masenjo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OK 1
# define KO 0

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_lststr_clear(t_list **lst);
int		ft_lststr_count_till_nl(t_list *list);
int		ft_lststr_chr(t_list *lst, char c);
int		ft_lststr_add_back(t_list **stash, char *content);
t_list	*ft_lstlast(t_list *lst);

#endif