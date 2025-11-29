# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 17:26:56 by masenjo           #+#    #+#              #
#    Updated: 2025/11/29 04:32:15 by masenjo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	= --silent

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

NAME        := so_long
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -fsanitize=address,undefined -Iinclude -g3

SRCDIR      := src
LIBFT_DIR   := lib/libft
PRINTF_DIR  := lib/ft_printf
GNL_DIR     := lib/gnl
MLX_LIB     := lib/libmlx_Linux.a
SYS_LIBS    := -lXext -lX11 -lm -lz

SRCS        := \
	$(SRCDIR)/main.c \
	$(SRCDIR)/init_game.c \
	$(SRCDIR)/utils.c \
	$(SRCDIR)/keys.c \
	$(SRCDIR)/hooks.c \
	$(SRCDIR)/map_parse.c \
	$(SRCDIR)/map_utils.c \
	$(SRCDIR)/path_find.c \
	$(SRCDIR)/assets.c \
	$(SRCDIR)/game_loop.c \
	$(SRCDIR)/animations.c \
	$(SRCDIR)/render.c \
	$(SRCDIR)/enemy.c \
	$(SRCDIR)/destroy.c


ALL_SRCS := $(SRCS)

OBJS        := $(ALL_SRCS:.c=.o)

LIBFT_A     := $(LIBFT_DIR)/libft.a
PRINTF_A    := $(PRINTF_DIR)/libftprintf.a
GNL_A       := $(GNL_DIR)/libgnl.a

.PHONY: all clean fclean re bonus

all:	$(NAME)
		@printf "\033[2K\r"
		@printf "$(GREEN)Compiled so_long -> $(NAME)$(NC)\n"

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_LIB) $(SYS_LIBS) -o $(NAME)

# Proyect objeccts
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	printf "\033[2K\r"
	@printf "$(GREEN)Compiling: $(NC)$<"

# Lbrary contstructon
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

$(GNL_A):
	$(MAKE) -C $(GNL_DIR)

# Cleaning
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	@printf "$(YELLOW)DELETED OBJECTS -> Libraries $(NC)\n"
	@printf "$(YELLOW)DELETED OBJECTS -> so_long $(NC)\n"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	@printf "$(RED)DELETED FULL PROYECT -> so_long $(NC)\n"

re::	fclean
re::	all
