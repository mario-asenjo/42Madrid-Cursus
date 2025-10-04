#include "get_next_line.h"

size_t  gnl_strlen(const char *s)
{
    size_t i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}

char    *gnl_strchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

char    *gnl_strjoin(char *s1, char *s2)
{
    size_t  len1 = gnl_strlen(s1);
    size_t  len2 = gnl_strlen(s2);
    char    *res = malloc(len1 + len2 + 1);
    size_t  i = 0, j = 0;
    if (!res)
        return NULL;
    while (s1 && s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    free(s1);
    return res;
}

t_gnl_list  *gnl_lstlast(t_gnl_list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next)
        lst = lst->next;
    return lst;
}

void    gnl_lstclear(t_gnl_list **lst)
{
    t_gnl_list *tmp;
    while (lst && *lst)
    {
        tmp = (*lst)->next;
        free((*lst)->content);
        free(*lst);
        *lst = tmp;
    }
}

void    gnl_lstadd_back(t_gnl_list **lst, char *content)
{
    t_gnl_list *new_node = malloc(sizeof(t_gnl_list));
    t_gnl_list *last;
    if (!new_node)
    {
        free(content);
        return;
    }
    new_node->content = content;
    new_node->next = NULL;
    if (!*lst)
        *lst = new_node;
    else
    {
        last = gnl_lstlast(*lst);
        last->next = new_node;
    }
}

size_t  gnl_linelen(t_gnl_list *lst)
{
    size_t len = 0, i;
    while (lst)
    {
        i = 0;
        while (lst->content && lst->content[i])
        {
            len++;
            if (lst->content[i] == '\n')
                return len;
            i++;
        }
        lst = lst->next;
    }
    return len;
}
