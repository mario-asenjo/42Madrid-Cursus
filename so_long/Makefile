# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masenjo <masenjo@student.42Madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 17:26:56 by masenjo           #+#    #+#              #
#    Updated: 2025/11/23 19:54:26 by masenjo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================
# Project
# =========================
NAME        := so_long

# =========================
# Toolchain
# =========================
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -fsanitize=address,undefined -Iinclude -g3

# =========================
# Directories
# =========================
SRCDIR      := src
LIBFT_DIR   := lib/libft
PRINTF_DIR  := lib/ft_printf
GNL_DIR     := lib/gnl
MLX_LIB     := lib/libmlx_Linux.a

# =========================
# System libs (elige una)
# macOS:  -framework OpenGL -framework AppKit
# Linux:  -lXext -lX11 -lm
# =========================
SYS_LIBS    := -lXext -lX11 -lm -lz

# =========================
# Source files (OBLIGATORIA)
# Añade/quita según tus ficheros reales
# =========================
SRCS        := \
	$(SRCDIR)/main.c \
	$(SRCDIR)/init_game.c \
	$(SRCDIR)/utils.c \
	$(SRCDIR)/keys.c \
	$(SRCDIR)/mouse.c \
	$(SRCDIR)/hooks.c \
	$(SRCDIR)/map_parse.c \
	$(SRCDIR)/map_utils.c \
	$(SRCDIR)/path_find.c \
	$(SRCDIR)/assets.c \
	$(SRCDIR)/game_loop.c \
	$(SRCDIR)/render.c \
	$(SRCDIR)/destroy.c

# =========================
# Source files (BONUS)
# Pon aquí tus *_bonus.c (mantén vacío si aún no hay)
# =========================
BONUS_SRCS  := \
	# $(SRCDIR)/enemy_bonus.c \
	# $(SRCDIR)/anim_bonus.c

# Con BONUS=1 se añaden los bonus al build
ifeq ($(BONUS),1)
	ALL_SRCS := $(SRCS) $(BONUS_SRCS)
else
	ALL_SRCS := $(SRCS)
endif

OBJS        := $(ALL_SRCS:.c=.o)

# =========================
# Libraries built by sub-Makefiles
# =========================
LIBFT_A     := $(LIBFT_DIR)/libft.a
PRINTF_A    := $(PRINTF_DIR)/libftprintf.a
GNL_A       := $(GNL_DIR)/libgnl.a

# =========================
# Rules (norme 42)
# =========================
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_LIB) $(SYS_LIBS) -o $(NAME)

# Proyect objeccts
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Lbrary contstructon
$(LIBFT_A):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) bonus -C $(PRINTF_DIR)

$(GNL_A):
	$(MAKE) bonus -C $(GNL_DIR)

# Cleaning
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

# Compile with bonus uses same rule as name rule and falls in ifeq statement
bonus:
	$(MAKE) BONUS=1
