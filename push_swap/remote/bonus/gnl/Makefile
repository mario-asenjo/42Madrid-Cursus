SRCS		=	get_next_line.c get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)

BONUS		=	get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJS	=	$(BONUS:.c=.o)

BONUS_FLAG	= 	.bonus_ok

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libgnl.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(BONUS_FLAG)

$(BONUS_FLAG): $(BONUS_OBJS)
				ar -rcs $(NAME) $(BONUS_OBJS)
				touch $(BONUS_FLAG)

.PHONY:			all clean fclean re bonus
