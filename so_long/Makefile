# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masenjo <masenjo@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 17:26:56 by masenjo           #+#    #+#              #
#    Updated: 2025/12/07 14:05:52 by masenjo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	= --silent

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -fsanitize=address,undefined -Iinclude -g3 -O0

SRCDIR      = src
LIBFT_DIR   = lib/libft
PRINTF_DIR  = lib/ft_printf
GNL_DIR     = lib/gnl
MLX_LIB     = lib/libmlx_Linux.a
SYS_LIBS    = -lXext -lX11 -lm -lz

SRCS        = \
	$(SRCDIR)/main.c \
	$(SRCDIR)/utils.c \
	$(SRCDIR)/keys.c \
	$(SRCDIR)/map_parse.c \
	$(SRCDIR)/game_loop.c \
	$(SRCDIR)/path_find.c \

BASE_SRCS	= \
	$(SRCDIR)/assets.c \
	$(SRCDIR)/destroy.c \
	$(SRCDIR)/init_game.c \
	$(SRCDIR)/map_utils.c \
	$(SRCDIR)/hooks.c \
	$(SRCDIR)/render.c

BONUS_SRCS	= \
	$(SRCDIR)/assets_bonus.c \
	$(SRCDIR)/destroy_bonus.c \
	$(SRCDIR)/init_game_bonus.c \
	$(SRCDIR)/map_utils_bonus.c \
	$(SRCDIR)/hooks_bonus.c \
	$(SRCDIR)/render_bonus.c \
	$(SRCDIR)/animations_bonus.c \
	$(SRCDIR)/enemy_bonus.c

ifeq ($(BONUS), 1)
	CFLAGS += -DBONUS=1
	ALL_SRCS = $(SRCS) $(BONUS_SRCS)
else
	ALL_SRCS = $(SRCS) $(BASE_SRCS)
endif

OBJS        = $(ALL_SRCS:.c=.o)

LIBFT_A     = $(LIBFT_DIR)/libft.a
PRINTF_A    = $(PRINTF_DIR)/libftprintf.a
GNL_A       = $(GNL_DIR)/libgnl.a

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
	rm -f $(SRCDIR)/*.o
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	@printf "$(RED)DELETED FULL PROYECT -> so_long $(NC)\n"

# bonus
bonus:
	$(MAKE) fclean
	$(MAKE) BONUS=1 all

re::	fclean
re::	all
