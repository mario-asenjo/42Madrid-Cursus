
#include "get_next_line.h"

static int  read_to_stash(int fd, t_gnl_list **stash)
{
    char    *buf;
    ssize_t bytes;
    int     found_nl = 0;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return -1;
    while (!found_nl)
    {
        bytes = read(fd, buf, BUFFER_SIZE);
        if (bytes <= 0)
            break;
        buf[bytes] = '\0';
        gnl_lstadd_back(stash, buf);
        if (gnl_strchr(buf, '\n'))
            found_nl = 1;
        if (!found_nl)
        {
            buf = malloc(BUFFER_SIZE + 1);
            if (!buf)
                return -1;
        }
    }
    if (!found_nl)
        free(buf);
    return (bytes);
}

static char *stash_to_line(t_gnl_list *stash)
{
    size_t  len = gnl_linelen(stash);
    char    *line;
    size_t  i = 0, j;

    if (len == 0)
        return NULL;
    line = malloc(len + 1);
    if (!line)
        return NULL;
    while (stash)
    {
        j = 0;
        while (stash->content && stash->content[j] && i < len)
            line[i++] = stash->content[j++];
        stash = stash->next;
    }
    line[i] = '\0';
    return line;
}

static void clean_stash(t_gnl_list **stash)
{
    t_gnl_list *node = *stash;
    t_gnl_list *new_stash = NULL;
    char *nl_ptr = NULL;
    size_t j = 0;

    while (node && !nl_ptr)
    {
        if (node->content)
            nl_ptr = gnl_strchr(node->content, '\n');
        if (!nl_ptr)
            node = node->next;
    }
    if (nl_ptr && *(nl_ptr + 1))
    {
        char *rest = malloc(gnl_strlen(nl_ptr + 1) + 1);
        if (!rest)
        {
            gnl_lstclear(stash);
            return;
        }
        while (nl_ptr[1 + j])
        {
            rest[j] = nl_ptr[1 + j];
            j++;
        }
        rest[j] = '\0';
        gnl_lstadd_back(&new_stash, rest);
    }
    gnl_lstclear(stash);
    *stash = new_stash;
}

char    *get_next_line(int fd)
{
    static t_gnl_list *stash = NULL;
    char    *line;
    int     r;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    r = read_to_stash(fd, &stash);
    if (r < 0 || !stash)
    {
        gnl_lstclear(&stash);
        return NULL;
    }
    line = stash_to_line(stash);
    clean_stash(&stash);
    return line;
}
