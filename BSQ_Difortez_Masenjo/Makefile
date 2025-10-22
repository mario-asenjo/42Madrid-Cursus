NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c solve_bsq.c process_map.c ft_s.c read_map.c checker.c
OBJS = $(SRCS:.c=.o)
HEADER = bsq.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
