#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

#endif
