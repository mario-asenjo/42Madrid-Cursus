#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
    char                *content;
    struct s_gnl_list   *next;
}   t_gnl_list;

// Funciones utilitarias
size_t      gnl_strlen(const char *s);
char       *gnl_strchr(const char *s, int c);
char       *gnl_strjoin(char *s1, char *s2);
t_gnl_list *gnl_lstlast(t_gnl_list *lst);
void        gnl_lstclear(t_gnl_list **lst);
void        gnl_lstadd_back(t_gnl_list **lst, char *content);
size_t      gnl_linelen(t_gnl_list *lst);

char    *get_next_line(int fd);

#endif
