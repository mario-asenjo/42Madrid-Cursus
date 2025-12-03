NAME		=	push_swap

CC			=	cc
CFLAGS 		=	-Wall -Wextra -Werror

MAKEFLAGS	=	--silent

GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
BOLD		=	\033[1m
RESET		=	\033[0m

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

SRC			=	push_swap.c \
				stack_init.c \
				stack_basic_ops.c \
				stack_swap_generic.c \
				parse_args.c \
				exit.c \
				ops_swap.c \
				ops_push.c \
				ops_rotate.c \
				ops_rev_rotate.c \
				sort_small.c \
				sort_utils.c \
				sort_big.c

OBJ			=	$(SRC:.c=.o)

# --------------------------------------------------------- #

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@printf "$(GREEN) Enlazando $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@printf "$(GREEN) COMPILADO $(NAME)$(RESET)\n"

$(LIBFT):
	@printf "$(BLUE) Compilando libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@printf "$(BLUE) Compilando ft_printf...$(RESET)\n"
	@$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	@printf "$(BLUE) Compilando \r $(RESET)"$>
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(YELLOW) Limpiando objetos de push_swap...$(RESET)\n"
	@rm -f $(OBJ)
	@printf "$(YELLOW) Limpiando objetos de libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(YELLOW) Limpiando objetos de ft_printf...$(RESET)\n"
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@printf "$(RED) Eliminando binario $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(RED) Eliminando librería libft...$(RESET)\n"
	@rm -f $(LIBFT)
	@printf "$(RED) Eliminando librería ft_print...$(RESET)\n"
	@rm -f $(PRINTF)

re: fclean all

.PHONY: all clean fclean re