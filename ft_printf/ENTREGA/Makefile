NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

SRCS =	ft_printf.c \
		ft_printf_numutils.c \
		ft_printf_strutils.c

BONUS_SRCS =	ft_printf_bonus.c \
				ft_printf_numutils_bonus.c \
				ft_printf_strutils_bonus.c \
				ft_printf_token_bonus.c \
				ft_printf_handlers_bonus.c \
				ft_printf_output_bonus.c \
				ft_printf_output_utils_bonus.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: fclean $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
