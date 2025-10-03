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
	char		*content;
	struct s_list	*next;
} t_list;

// Gestión de listas

void	ft_lstclear(t_list **lst);

#endif
