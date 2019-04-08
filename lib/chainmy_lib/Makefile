##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compiles the libmy.a library binary
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

NAME	=	chainmy
COLOR_THEME	=	$(MAGEN_C)
MY_PATH	=	.
INCLUDE_PATH	=	../../include

SRC_MY	=	my_chained/double_chain_push.c \
			my_chained/double_chain_pop.c \
			my_chained/simple_chain.c \
			my_vector/my_simple_vector.c \
			my_vector/double_vector_push.c \
			my_vector/double_vector_pop.c

CFLAGS	=	-Wall \
			-W \
			-Werror \
			-I $(INCLUDE_PATH)

SRCS	=	$(SRC_MY:%=$(MY_PATH)/%)

OBJ	=	$(SRCS:.c=.o)

all:	message $(NAME)

$(NAME):	$(OBJ)
	@ar rc ./lib$(NAME).a $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\nCOMPILED:" $(DEFAULT)$(LIGHT_GREEN) "lib$(NAME).a\n" $(DEFAULT) || \
		$(ECHO) $(RED_C)$(UNDLN_T)$(BOLD_T)"BUILD FAILED:" $(LIGHT_RED) "lib$(NAME).a"$(DEFAULT)"\n"

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  _________   ___ ___    _____  .___ _______                   " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  \_   ___ \ /   |   \  /  _  \ |   |\      \     _____ ___.__." $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  /    \  \//    ~    \/  /_\  \|   |/   |   \   /     <   |  |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  \     \___\    Y    /    |    \   /    |    \ |  Y Y  \___  |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"   \______  /\___|_  /\____|__  /___\____|__  / |__|_|  / ____|" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"          \/       \/         \/            \/        \/\/     " $(DEFAULT)
	@$(LINE_RETURN)

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"lib$(NAME)'s object files"$(DEFAULT)

fclean:	clean
	@$(RM) ./lib$(NAME).a
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary lib$(NAME).a"$(DEFAULT)

re:		fclean all

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) message clean fclean re
