##
## EPITECH PROJECT, 2018
## Fairefichier
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

NAME	=	my
COLOR_THEME	=	$(LIGHT_GREEN)

MY_PATH	=	./my
PRINTF_PATH	=	./my
INCLUDE_PATH	=	../include

SRC_MY	=	my_swap.c					\
			my_putstr.c					\
			my_strlen.c					\
			my_getnbr.c					\
			my_strcpy.c					\
			my_putchar.c				\
			my_revstr.c					\
			my_put_nbr.c				\
			my_intlen.c					\
			my_check_occur.c			\
			my_strdup.c					\
			my_strncpy.c				\
			my_strcmp.c					\
			my_strlowcase.c				\
			my_get_one_nbr.c			\
			my_int_to_char.c			\
			get_next_line.c				\
			my_str_to_word_array.c		\
			my_str_isalpha.c			\
			my_str_islower.c			\
			my_str_isprintable.c		\
			my_str_isupper.c			\
			my_strcat.c					\
			my_strncat.c				\
			my_strncmp.c				\
			my_strstr.c					\
			my_strupcase.c				\
			my_strxdup.c				\
			my_swap.c					\
			my_compute_power_rec.c		\
			my_compute_square_root.c	\
			my_is_prime.c				\
			my_isneg.c					\
			my_tab_len.c				\
			my_put_err.c				\
			my_str_isnum.c				\
			my_is_alpha_num.c			\
			randomiser.c				\
			my_realloc.c				\
			my_itoa.c 					\
			my_atoi.c

SRC_PRINTF	=	my_printf.c			\
				binary.c			\
				hexa.c				\
				octal.c				\
				put_pointers.c		\
				put_unsig.c			\
				print_binary.c		\
				print_hexa.c		\
				print_octal.c		\
				print_pointers.c	\
				print_str.c			\
				print_nbr.c			\
				print_unsig.c		\
				print_str_s.c		\
				print_char.c		\
				list.c				\
				putstr_s.c			\
				octal2.c

CFLAGS	=	-Wall \
			-Wextra \
			-Werror \
			-I $(INCLUDE_PATH)

DEBUG_FLAGS	=	-g3 -gdwarf-4

SRCS	=	$(SRC_MY:%=$(MY_PATH)/%)
SRCS	+=	$(SRC_PRINTF:%=$(PRINTF_PATH)/%)

OBJ	=	$(SRCS:.c=.o)

all:	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _     _ _                          " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   (_) |__  _ __ __ _ _ __ _   _ " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   | | '_ \| '__/ _\` | '__| | | |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |___| | |_) | | | (_| | |  | |_| |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_____|_|_.__/|_|  \__,_|_|   \__, |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"                              |___/ " $(DEFAULT)
	@$(LINE_RETURN)

$(NAME):	$(OBJ)
	@ar rc ./lib$(NAME).a $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "lib$(NAME).a" $(DEFAULT) || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "lib$(NAME).a"$(DEFAULT)

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

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(CYAN_C)
debug: all

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) message clean fclean re debug
