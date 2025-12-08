# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 09:08:04 by masenjo           #+#    #+#              #
#    Updated: 2025/12/08 09:08:05 by masenjo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAGS 		=	-Wall -Wextra -Werror -g3

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
				parse_args_utils.c \
				exit.c \
				ops_swap.c \
				ops_push.c \
				ops_rotate.c \
				ops_rev_rotate.c \
				sort_small.c \
				sort_utils.c \
				sort_big.c \
				indexing.c

OBJ			=	$(SRC:.c=.o)

BONUS_NAME	=	checker_masenjo
GNL			=	bonus/gnl/libgnl.a
BONUS_SRC	=	bonus/push_swap_checker_bonus.c \
				stack_init.c \
				stack_basic_ops.c \
				stack_swap_generic.c \
				parse_args.c \
				parse_args_utils.c \
				ops_swap.c \
				ops_push.c \
				ops_rotate.c \
				exit.c \
				ops_rev_rotate.c


BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

# --------------------------------------------------------- #

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@printf "$(GREEN) Linking... $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@printf "$(GREEN) Compiled! $(NAME)$(RESET)\n"

$(LIBFT):
	@printf "$(BLUE) Compiling libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@printf "$(BLUE) Compiling ft_printf...$(RESET)\n"
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL):
	@printf "$(BLUE) Compiling get_next_line...$(RESET)\n"
	@$(MAKE) -C bonus/gnl bonus

%.o: %.c
	@printf "$(BLUE) Compiling \r $(RESET)"$>
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(GNL)
	@printf "$(GREEN) Compiling el checker... $(RESET)\n"
	@printf "$(YELLOW) Compiling el checker... $(RESET)\n"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(GNL) -o $(BONUS_NAME)
	@printf "$(GREEN) Compiled $(BONUS_NAME) $(RESET)\n"
	@printf "$(RED) Deleting object files from gnl $(RESET)\n"
	@$(MAKE) -C bonus/gnl clean

clean:
	@printf "$(YELLOW) Cleaning object in push_swap...$(RESET)\n"
	@rm -f $(OBJ)
	@printf "$(YELLOW) Cleaning object in libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(YELLOW) Cleaning object in ft_printf...$(RESET)\n"
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@printf "$(RED) Cleaning binary... $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(RED) Cleaning library libft...$(RESET)\n"
	@rm -f $(LIBFT)
	@printf "$(RED) Cleaning library ft_print...$(RESET)\n"
	@rm -f $(PRINTF)

re: fclean all

.PHONY: all clean fclean re bonus