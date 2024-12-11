NAME	=	get_next_line

NAMEB	=	get_next_line_bonus

SRC		=	main.c get_next_line.c get_next_line_utils.c

SRCB	=	main.c get_next_line_bonus.c get_next_line_utils_bonus.c

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

OBJ		=	$(SRC:.c=.o)

OBJB		=	$(SRCB:.c=.o)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

all		:	$(NAME)

bonus	:	$(NAMEB)

$(NAME)	:	$(OBJ)
			$(CC) -o $@ $^ $(CFLAGS)

$(NAMEB):	$(OBJB)
			$(CC) -o $@ $^ $(CFLAGS)

clean	:
			rm -f $(OBJ) $(OBJB)

fclean	:	clean
			rm -f $(NAME) $(NAMEB)

re		:	fclean all

.PHONY	: all clean fclean re
