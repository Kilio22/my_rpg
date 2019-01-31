##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

INC_DIR	=	../include/

NAME	=	libg.a

CFLAGS	=	-Wall -Wextra -I $(INC_DIR)

LDFLAGS	=	-L $(LIBG_DIR) -lmy

SRC	=	pp_hitbox.c

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
