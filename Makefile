##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Main project's Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
DEFAULT_C	=	"\e[39m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME	=	executable
COLOR_THEME	=	$(BLUE_C)
LIB_NAME	=	my
LIBG_NAME	=	g
SRC_NAME	=	src
INCL_NAME	=	include
TESTS_NAME	=	tests

ROOT_PATH	=	./
LIB_PATH	=	./lib
LIBG_PATH 	=	./lib_graphic/
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)

SRC	=	event.c	\
		create_house.c

SRCS	=	$(SRC:%=$(SRC_PATH)/%) \
			$(SRC_PATH)/main.c

OBJ	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall \
			-W \
			-I $(INCL_PATH) \
			-L$(LIB_PATH) -l$(LIB_NAME) \
			-L$(LIBG_PATH) -l$(LIBG_NAME) \
			-lcsfml-graphics \
			-lcsfml-window \
			-lcsfml-system

all:	message $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH) -s
	@make -C $(LIBG_PATH) -s
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)"$(DEFAULT)"\n" || \
		$(ECHO) $(BOLD_T)$(UNDLN_T)$(RED_C)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)"$(DEFAULT)"\n"

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" ____  ____   ____ " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ \|  _ \ / ___|" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_) | |_) | |  _ " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ <|  __/| |_| |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_| \_\_|    \____|" $(DEFAULT)
	@$(LINE_RETURN)

clean:
	@make clean -C $(LIB_PATH) -s
	@make clean -C $(LIBG_PATH) -s
	@make clean -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean:	clean
	@make fclean -C $(LIB_PATH) -s
	@make fclean -C $(LIBG_PATH) -s
	@make fclean -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

tests_run:	fclean
	@make -C $(LIB_PATH) -s
	@make -C $(LIB_TESTS_PATH) -s
	@make -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"
	@$(ECHO) $(RED_C)""
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
	@$(ECHO) $(DEFAULT)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) message clean fclean re tests_run