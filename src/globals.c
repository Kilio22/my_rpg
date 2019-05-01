/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#include "rpg.h"

const char *key_str[] = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "ESC",
    "LCTRL",
    "LSHIFT",
    "LALT",
    "LSYSTEM",
    "RCTRL",
    "RSHIFT",
    "RALT",
    "RSYSTEM",
    "MENU",
    "[",
    "]",
    ";",
    ", ",
    ".",
    "'",
    "/",
    "\\",
    "~",
    " = ",
    "-",
    "SPACE",
    "ENTER",
    "BACKSPACE",
    "TAB",
    "PAGE_UP",
    "PAGE_DOWN",
    "END",
    "HOME",
    "INSERT",
    "DELETE",
    "+",
    "-",
    "*",
    "/",
    "L_ARROW",
    "R_ARROW",
    "UP_ARROW",
    "DOWN_ARROW",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "F13",
    "F14",
    "F15",
    "PAUSE"
};

const char *menu_path[][2] = {
    {"assets/menu_image.png",
    "assets/menu_image.png"},
    {"assets/loading_fr.png", "assets/loading_en.png"},
    {"assets/option_key_fr.png",
    "assets/option_key_en.png"}
};

const char *menu_str[][6] = {
    {
        " Nouvelle Partie ",
        "Charger une partie",
        "   Parametres",
        "    Tutoriel",
        "    Credits",
        "     Quitter"
    },
    {
        " New Game ",
        " Load Game ",
        "   Settings ",
        "How To Play ",
        "   Credits ",
        "     Quit "
    }
};

const char *menu_desc[][6] = {
    {
        "Commencer une nouvelle aventure !",
        "Charger un partie sauvegardee pour la continuer !",
        "Changer l'experience de jeu en selectionnant une autre\nlangue"
        ", en modifiant le volume de la musique, \n"
        "ou en changeant les controles !",
        "Apprendre a jouer a ce jeu !",
        "Regarder les credits du jeu !",
        "Retourner au bureau"
    },
    {
        "Start a new adventure !",
        "Load one of the saved adventure and continue it !",
        "Change your experience by selecting an other language, \n"
        "modify the volume"
        " of the music, or by define \nyour propers controls !",
        "Learn how to play to this game !",
        "View the credits",
        "Go back to the deskdop"
    }
};

const char *obj_path[] = {
    "assets/hero_hitbox.png",
    "assets/hero.png",
    "assets/map_hitbox.png",
    "assets/ennemi.png",
    "assets/stupid_nathan.png",
    "assets/Aubergiste.png",
    "assets/perso_vert.png"
};

const sfVector2f menu_pos[6] = {
    {110, 60},
    {100, 160},
    {100, 260},
    {100, 360},
    {115, 460},
    {90, 560}
};

const char *settings_fp[5] = {
    "assets/menu_image.png",
    "assets/up_vol.png",
    "assets/down_vol.png",
    "assets/fr.png",
    "assets/eng.png"
};

const sfVector2f settings_spr_pos[5] = {
    {0, 0},
    {500, 70},
    {780, 70},
    {520, 200},
    {720, 200}
};

const char *settings_str[][4] = {
    {
        "VOLUME",
        "NULL",
        "LANGAGE",
        "CONTROLES"
    },
    {
        "VOLUME",
        "NULL",
        "LANGUAGE",
        "CONTROLS"
    }
};

const sfVector2f settings_pos[4] = {
    {110, 60},
    {640, 60},
    {65, 200},
    {400, 360},
};

const char *save_path[3] = {
    "saves/save1.txt",
    "saves/save2.txt",
    "saves/save3.txt"
};

const char *house_path[8] = {
    "assets/maison1.png",
    "assets/maison2.png",
    "assets/auberge.png",
    "assets/forge.png",
    "assets/church.png",
    "assets/maison3.png",
    "assets/maison4.png",
    "assets/maison5.png"
};

const char *ennemi_text[][2] = {
    {"Ennemi: Viens te battre !",
    "Enemy: Come fight me !"},
    {"Ennemi: Tu es venu te faire tuer ?",
    "Enemy: You came to die ?"},
    {"Ennemi: Pauvre fou, tu vas souffrir !",
    "Enemy: Poor fool, you will suffer !"},
    {"Vous etes mort. Vous avez ete transporte a l'auberge et avez ete soigne.",
    "You died. You were transported to the inn and were healed."},
    {"Bravo, vous avez vaincu votre adversaire !\n",
    "Congratulations, you have defeated your opponent !\n"},
    {"Vous avez gagne un niveau, et un nouvel objet !",
    "You have gained a level, and a new object !"}
};

const sfIntRect house_rects[8] = {
    {0, 0, 160, 320},
    {0, 0, 224, 256},
    {0, 0, 320, 448},
    {0, 0, 192, 352},
    {0, 0, 384, 352},
    {0, 0, 288, 288},
    {0, 0, 192, 288},
    {0, 0, 192, 384}
};

const int fog_off[54][2] = {
    {11, 15},
    {9, 17},
    {7, 19},
    {6, 20},
    {5, 21},
    {5, 21},
    {4, 21},
    {4, 21},
    {3, 21},
    {3, 21},
    {3, 21},
    {2, 21},
    {2, 21},
    {1, 20},
    {1, 20},
    {1, 20},
    {1, 20},
    {1, 20},
    {1, 20},
    {2, 21},
    {2, 21},
    {3, 21},
    {3, 21},
    {3, 21},
    {3, 21},
    {3, 22},
    {4, 22},
    {4, 22},
    {4, 22},
    {4, 22},
    {5, 22},
    {5, 22},
    {5, 22},
    {5, 22},
    {5, 22},
    {5, 22},
    {4, 22},
    {4, 21},
    {4, 21},
    {4, 21},
    {4, 20},
    {4, 20},
    {4, 20},
    {4, 19},
    {3, 19},
    {3, 19},
    {3, 19},
    {3, 20},
    {3, 20},
    {3, 20},
    {3, 21},
    {4, 21},
    {3, 22},
    {2, 23}
};

const sfVector2f door_pos[8] = {
    {0, 256},
    {0, 192},
    {160, 352},
    {95, 160},
    {0, 256},
    {192, 224},
    {0, 224},
    {96, 320}
};

const sfIntRect door_rects[8] = {
    {0, 64, 96, 64},
    {0, 0, 96, 64},
    {0, 352, 96, 96},
    {0, 224, 96, 64},
    {0, 224, 96, 64},
    {0, 64, 96, 64},
    {0, 64, 96, 64},
    {0, 0, 96, 64},
};

intro_menu_t menu[6] = {
    menu_new_game,
    menu_load_game,
    menu_settings,
    menu_how_to_play,
    menu_credit,
    menu_close_window
};

intro_pointer_t intro[] = {
    intro_control,
    intro_control,
    intro_ennemi_ctrl,
    intro_ennemi_two,
    intro_ennemi_two,
    intro_port,
    intro_port,
    intro_port,
    intro_nathan,
    intro_nathan,
    intro_nathan_echelle,
    intro_nathan_echelle,
    intro_nathan_dialogue,
    intro_go_auberge,
    intro_go_auberge,
    intro_go_auberge2,
    intro_go_auberge2,
    intro_go_auberge3,
    intro_go_auberge4,
    intro_go_auberge5,
    intro_go_auberge6,
    intro_go_auberge7,
    intro_go_auberge8,
    intro_go_auberge9,
    intro_go_auberge10,
    intro_go_auberge11,
    intro_go_auberge12,
    intro_go_auberge13,
    intro_go_auberge13,
    intro_go_auberge14,
    intro_go_auberge14,
    intro_go_auberge14,
    intro_go_auberge15,
    intro_go_auberge16,
    intro_go_auberge16,
    intro_go_auberge16,
    intro_go_auberge17,
    intro_go_auberge17,
    intro_go_auberge18,
    intro_go_auberge19,
    intro_go_auberge19,
    intro_go_auberge20,
    intro_go_auberge20,
    intro_go_auberge20
};

const char *menu_font = "assets/menu_font_h.ttf";

const char *pause_str[][3] = {
    {"REPRENDRE",
    "RETOUR AU MENU",
    "QUITTER"},
    {"RESUME",
    "MAIN MENU",
    "QUIT"}
};

const sfVector2f vect_pause[][3] = {
    {
        {450, 220},
        {370, 320},
        {485, 420}
    },
    {
        {530, 220},
        {490, 320},
        {580, 420}
    }
};

const int tab_stats[][6] = {
    {1, 0, 30, 15, 1, 10},
    {1, 0, 100, 1, 1, 2},
    {1, 0, 50, 7, 5, 5},
    {1, 0, 200, 20, 8, 12},
    {1, 0, 150, 15, 5, 8},
    {1, 0, 400, 25, 10, 15}
};

const int level_up[][3][6] = {
    {
        {10, 1, 2, 1},
        {2, 1, 1, 1},
        {3, 2, 2, 0}
    },
    {
        {5, 2, 1, 2},
        {2, 1, 1, 1},
        {3, 3, 2, 0}
    },
    {
        {10, 1, 2, 1},
        {2, 1, 1, 1},
        {3, 2, 2, 0}
    }
};