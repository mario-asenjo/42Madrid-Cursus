SRCS	=	ft_printf_numutils.c \
			ft_printf_strutils.c \
			ft_printf.c

BONUS_SRCS = 	ft_printf_bonus.c \
				ft_printf_numutils_bonus.c \
				ft_printf_strutils_bonus.c \
				ft_printf_token_bonus.c

OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

#bonus:		$(OBJS) $(BONUS_OBJS)
#				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

re:				fclean all

.PHONY:		all clean fclean re bonus