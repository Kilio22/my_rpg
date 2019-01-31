##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

SRC_DIR	=	src/
LIB_DIR	=	lib/
INC_DIR	=	include/
LIBG_DIR =	lib_graphic/

NAME	=	executable

CFLAGS	=	-g -Wall -Wextra -I $(INC_DIR)

LDFLAGS	=	-L $(LIB_DIR) -L $(LIBG_DIR) -l my -l g -l csfml-graphics -l csfml-system

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)event.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	make -C $(LIBG_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(LIBG_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	make fclean -C $(LIBG_DIR)
	$(RM) $(NAME)
	mr_clean

re:	fclean all
