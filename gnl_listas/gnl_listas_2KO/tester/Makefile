# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME = gnl_test
SRC = get_next_line.c get_next_line_utils.c tester.c
HDR = get_next_line.h
EXTRA = memwrap.c
BUFFERS = 1 2 8 32 1024

CC = cc
CFLAGS = -Wall -Wextra -Werror

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all:
	@echo "Use 'make test' or 'make memtest'"

test: $(addprefix run_, $(BUFFERS))

$(addprefix run_, $(BUFFERS)): run_%:
	@echo "\n\033[1;34m=== BUFFER_SIZE=$* ===\033[0m"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$* $(SRC) -o $(NAME)_$*
	@./$(NAME)_$*
	@rm -f $(NAME)_$*

memtest:
	@echo "\n\033[1;33m=== VALGRIND MEMORY TEST (BUFFER_SIZE=32) ===\033[0m"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=32 $(SRC) $(EXTRA) -o $(NAME)_mem
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)_mem
	@rm -f $(NAME)_mem

clean:
	@rm -f $(NAME)_*

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test memtest
