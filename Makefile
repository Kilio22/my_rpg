##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier, made by HeyShafty
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
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME	=	my_rpg
COLOR_THEME	=	$(BLUE_C)
TESTS_COLOR_THEME	=	$(RED_C)

ROOT_PATH	=	./
SRC_NAME	=	src
INCL_NAME	=	include
TESTS_NAME	=	tests
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
MENU_PATH	=	menu/
SETTINGS_PATH	=	settings/
INTRO_PATH	=	intro/

SRC	=	$(INTRO_PATH)intro.c	\
		$(INTRO_PATH)intro_event.c	\
		$(INTRO_PATH)intro_move.c	\
		$(INTRO_PATH)intro_text.c	\
		$(INTRO_PATH)intro_steps.c	\
		$(INTRO_PATH)intro_steps_2.c	\
		$(INTRO_PATH)intro_steps_3.c	\
		$(INTRO_PATH)intro_steps_4.c	\
		$(INTRO_PATH)intro_steps_5.c	\
		$(INTRO_PATH)intro_steps_6.c	\
		$(INTRO_PATH)dialogue.c	\
		$(INTRO_PATH)intro_create.c	\
		$(MENU_PATH)analyse_menu_key.c	\
		$(MENU_PATH)analyse_menu_mouse.c	\
		$(MENU_PATH)check_save_status.c	\
		$(MENU_PATH)destroy_menu.c	\
		$(MENU_PATH)load_game.c	\
		$(MENU_PATH)load_game_event.c	\
		$(MENU_PATH)menu_display.c	\
		$(MENU_PATH)menu_event.c 	\
		$(MENU_PATH)menu_fcts.c	\
		$(MENU_PATH)menu_init.c	\
		$(MENU_PATH)new_game.c	\
		$(MENU_PATH)new_game_event.c	\
		$(SETTINGS_PATH)controls_events.c	\
		$(SETTINGS_PATH)controls_init.c	\
		$(SETTINGS_PATH)settings_events.c	\
		$(SETTINGS_PATH)settings_init.c	\
		$(SETTINGS_PATH)settings_menu.c	\
		$(SETTINGS_PATH)settings_utils.c	\
		analyse_game_key.c	\
		camera_gestion.c	\
		character_gestion.c \
		characters_animation.c	\
		characters_stats.c	\
		create_house.c	\
		create_obj.c	\
		fill_map.c	\
		free_save.c	\
		free.c 	\
		game_display.c	\
		game_event.c	\
		game_init.c \
		globals.c	\
		house_display.c	\
		init_save.c	\
		layout_init.c 	\
		list.c 	\
		map_init.c	\
		music.c \
		my_utils.c	\
		print_map.c	\
		time_gestion.c \
		item/item.c \
		inventory/inventory_debug.c \
		inventory/inventory_op.c \
		inventory/inventory.c \
		inventory/inventory_swap.c \
		inventory/inventory_core.c \
		inventory/inventory_stock.c \
		inventory/inventory_stuff.c	\
		game_create.c			\
		my_other_utils.c

SRC_LIB	=	inimy \
			g 	\
			list \
			graphmy \
			filemy \
			chainmy \
			stringmy \
			dispmy \
			my \
			graphic \
			list

LIB_PATHS	=	lib/lib_my \
				lib/lib_graphic \
				lib/lib_list \
				lib/graphmy_lib \
				lib/stringmy_lib \
				lib/chainmy_lib \
				lib/inimy_lib \
				lib/filemy_lib \
				lib/dispmy_lib

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.c
OBJ	=	$(SRCS:.c=.o)
LIBRARIES	=	$(SRC_LIB:%=-l%)
LIB_PATHS_FLAG	=	$(LIB_PATHS:%=-L$(ROOT_PATH)%)

CFLAGS	=	-Wall \
			-Wextra \
			-I $(INCL_PATH) \
			$(LIB_PATHS_FLAG) \
			$(LIBRARIES) \
			-lcsfml-graphics \
			-lcsfml-window \
			-lcsfml-system \
			-lcsfml-audio

DEBUG_FLAGS	=	-g3 -gdwarf-4
MAKE_RULE	=	all
CLEAN_RULE	=	clean

all:	build_libs message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _     _____   ____  _____ ____ _____   ____  ____   ____ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   | ____| | __ )| ____/ ___|_   _| |  _ \|  _ \ / ___|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   |  _|   |  _ \|  _| \___ \ | |   | |_) | |_) | |  _ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |___| |___  | |_) | |___ ___) || |   |  _ <|  __/| |_| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_____|_____| |____/|_____|____/ |_|   |_| \_\_|    \____|"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

build_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make -C $$MAKE_PATH $(MAKE_RULE) -s ; \
	done

clean_libs: $(LIB_PATHS)
	@for MAKE_PATH in $(LIB_PATHS) ; do \
		make $(CLEAN_RULE) -C $$MAKE_PATH -s ; \
	done
	@make $(CLEAN_RULE) -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"

clean: clean_libs
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean: CLEAN_RULE=fclean
fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(CYAN_C)
debug: MAKE_RULE = debug
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run: build_libs
	@make -C $(TESTS_PATH) -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_COLOR_THEME)" \
		LIB_PATHS="$(LIB_PATHS)" \
		LIBRARIES="$(LIBRARIES)"
	@$(ECHO) $(TESTS_COLOR_THEME)""
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@$(ECHO) $(BOLD_T)""
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
	@$(ECHO) $(DEFAULT)

%.o: %.c
	@$(CC) -c $(CFLAGS) -g3 -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) build_libs message clean_libs clean fclean re debug tests_run
