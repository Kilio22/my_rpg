##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

INC_DIR	=	../include/

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -I $(INC_DIR)

LDFLAGS	=	-L $(LIB_DIR) -lmy

SRC	=	my_itoa.c		\
		my_atoi.c		\
		my_putchar.c	\
		my_putnbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_strdup.c		\
		my_strlen.c		\
		randomiser.c	\
		my_realloc.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
