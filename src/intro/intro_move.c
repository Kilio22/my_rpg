/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_move
*/

#include "rpg.h"

void display_house_intro(obj_t **obj, house_t *house, rpg_t *rpg, int *opt)
{
    if (house->frame_animation > 8 && house->door_rect.left < 384 - 96) {
        animation(&house->door_rect, 0, 96, 384);
        house->frame_animation = 0;
    }
    house->frame_animation++;
    if (house->door_rect.left > 384 - 97) {
        house->display_house = 0;
        (*opt)++;
    }
}

void check_house_display_intro(obj_t **obj, house_t *house, rpg_t *rpg, int *opt)
{
    if (house->display_house == 1)
        display_house_intro(obj, house, rpg, opt);
    else
        do_not_display_house(obj[8], house, rpg, obj);
}

static int intro_go_auberge20(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 41) {
        new_pos.y = 1;
        sfSprite_move(obj[0]->sprite, new_pos);
        sfSprite_move(obj[8]->sprite, new_pos);
        sfSprite_move(obj[10]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    if (opt == 42 && rpg->quest_status == 24) {
        //free_obj(5 a 10);
        sfSprite_setPosition(obj[0]->sprite, V2F(9410, 1250));
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        //free_house(0);
        for (int i = 5; i < 11; i++)
            obj[i] = NULL; //a enlever
        house[0] = NULL; //a enlever
        house[0] = create_house(2, V2F(9200, 768));
        obj[2] = create_object("assets/stupid_nathan.png", (sfVector2f){obj[0]->pos.x - 50, obj[0]->pos.y}, (sfIntRect){0, 0, 32, 64}, sfFalse);
        obj[3] = create_object("assets/perso_vert.png", (sfVector2f){obj[0]->pos.x - 100, obj[0]->pos.y}, (sfIntRect){0, 0, 32, 64}, sfFalse);
        sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
        sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});
        GAME.follower = init_list(obj[0]->pos.x - 50, obj[0]->pos.y);
        GAME.follower2 = init_list(obj[0]->pos.x - 100, obj[0]->pos.y);
        printf("ok\n");
    }
    if (rpg->quest_status == 25)
        MENU.menu_on = 2;
    return opt;
}

static int intro_go_auberge19(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 39 && rpg->quest_status == 22) {
        if (obj[10]->pos.x > 9408) {
            new_pos.x = -1;
            sfSprite_move(obj[10]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 40) {
        if (obj[10]->pos.y < 1026) {
            new_pos.y = 1;
            sfSprite_move(obj[10]->sprite, new_pos);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    return intro_go_auberge20(obj, opt, rpg, house);
}

static int intro_go_auberge18(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 38) {
        if (obj[0]->pos.y > 1130) {
            new_pos.y = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            rpg->quest_status++;
            opt++;
        }
    }
    return intro_go_auberge19(obj, opt, rpg, house);
}

static int intro_go_auberge17(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 36 && rpg->quest_status == 14) {
        if (obj[0]->pos.y < 1150) {
            new_pos.y = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 37) {
        if (obj[0]->pos.x < 9408) {
            new_pos.x = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge18(obj, opt, rpg, house);
}

static int intro_go_auberge16(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 33) {
        if (obj[0]->pos.y > 1000) {
            new_pos.y = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if ((opt == 34 || opt == 35) && rpg->quest_status == 13) {
        new_pos.x = -1;
        sfSprite_move(obj[10]->sprite, new_pos);
        new_pos.x = 0;
        new_pos.y = 1;
        sfSprite_move(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    return intro_go_auberge17(obj, opt, rpg, house);
}

static int intro_go_auberge15(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 32) {
        if (obj[0]->pos.x > 9266) {
            new_pos.x = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    return intro_go_auberge16(obj, opt, rpg, house);
}

static int intro_go_auberge14(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};
    if (opt == 29) {
        if (obj[8]->pos.y > 1060) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    if (opt == 30 || opt == 31) {
        new_pos.y = 1;
        sfSprite_move(obj[8]->sprite, new_pos);
        opt++;
    }
    return intro_go_auberge15(obj, opt, rpg, house);
}

static int intro_go_auberge13(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};
    (void)rpg;
    if (opt == 27) {
        if (obj[8]->pos.y > 1192) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 28) {
        house[0]->display_house = 1;
        check_house_display_intro(obj, house[0], rpg, &opt);
    }
    return intro_go_auberge14(obj, opt, rpg, house);
}

static int intro_go_auberge12(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 26) {
        if (obj[0]->pos.x > 9408) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = -1;
            new_pos.y = 0;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge13(obj, opt, rpg, house);
}

static int intro_go_auberge11(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 25) {
        if (obj[8]->pos.x > 9408) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge12(obj, opt, rpg, house);
}

static int intro_go_auberge10(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 24) {
        if (obj[0]->pos.y < 1296) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = 0;
            new_pos.y = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge11(obj, opt, rpg, house);
}

static int intro_go_auberge9(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 23) {
        if (obj[8]->pos.y < 1268) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge10(obj, opt, rpg, house);
}

static int intro_go_auberge8(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 22) {
        if (obj[0]->pos.x > 10834) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = -1;
            new_pos.y = 0;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge9(obj, opt, rpg, house);
}

static int intro_go_auberge7(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 21) {
        if (obj[8]->pos.x > 10834) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge8(obj, opt, rpg, house);
}

static int intro_go_auberge6(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 20) {
        if (obj[0]->pos.y < 1104) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = 0;
            new_pos.y = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge7(obj, opt, rpg, house);
}

static int intro_go_auberge5(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 19) {
        if (obj[8]->pos.y < 1076) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge6(obj, opt, rpg, house);
}

static int intro_go_auberge4(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 18) {
        if (obj[0]->pos.x > 11376) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.y = 0;
            new_pos.x = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge5(obj, opt, rpg, house);
}

static int intro_go_auberge3(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 17) {
        if (obj[8]->pos.x > 11376) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge4(obj, opt, rpg, house);
}

static int intro_go_auberge2(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 15) {
        if (obj[8]->pos.x > 11436) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 16) {
        if (obj[0]->pos.y > 910) {
            new_pos.y = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge3(obj, opt, rpg, house);
}

static int intro_go_auberge(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 13 && rpg->quest_status == 10) {
        if (obj[8]->pos.y > 882) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 14) {
        if (obj[0]->pos.x > 11500) {
            new_pos.x = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return intro_go_auberge2(obj, opt, rpg, house);
}

static int intro_nathan_dialogue(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 12) {
        if (obj[8]->pos.x < 11502) {
            new_pos.x = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            rpg->quest_status++;
            clock_text_intro(0);
            opt++;
        }
    }
    return intro_go_auberge(obj, opt, rpg, house);
}

static int intro_nathan_echelle(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 10) {
        if (obj[8]->pos.x < 11500) {
            new_pos.x = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 11) {
        if (obj[8]->pos.y < 1096) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    return intro_nathan_dialogue(obj, opt, rpg, house);
}

static int intro_nathan(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 8 && rpg->quest_status == 4) {
        if (obj[8]->pos.x < 11376) {
            new_pos.x = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 9) {
        if (obj[8]->pos.y > 882) {
            new_pos.y -= 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else {
            rpg->quest_status++;
            clock_text_intro(0);
            opt++;
        }
    }
    return intro_nathan_echelle(obj, opt, rpg, house);
}

static int intro_port(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 5 && rpg->quest_status == 3) {
        new_pos.x = 11556;
        new_pos.y = 1122;
        sfSprite_setPosition(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    if (opt == 6 || opt == 7) {
        new_pos.x = 0;
        new_pos.y = 1;
        sfSprite_move(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    return intro_nathan(obj, opt, rpg, house);
}

static int intro_ennemi_two(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 3  || opt == 4) {
        (new_pos).x -= 1;
        sfSprite_move(obj[6]->sprite, new_pos);
        (new_pos).x += 2;
        sfSprite_move(obj[7]->sprite, new_pos);
        opt++;
    }
    return (intro_port(obj, opt, rpg, house));
}

static int intro_ennemi_ctrl(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 2) {
        if (obj[0]->pos.y > 1900) {
            (new_pos).y -= 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
            (new_pos).y += 2;
            sfSprite_move(obj[5]->sprite, new_pos);
            sfSprite_move(obj[6]->sprite, new_pos);
            sfSprite_move(obj[7]->sprite, new_pos);
        } else
            opt++;
    }
    return (intro_ennemi_two(obj, opt, rpg, house));
}

void intro_control(obj_t **obj, rpg_t *rpg, house_t **house)
{
    static int opt = 0;
    sfVector2f new_pos = {0, 0};

    if (opt == 0) {
        if (obj[0]->pos.y > 2076) {
            new_pos.y -= 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 1) {
        if (obj[0]->pos.x > 10194) {
            new_pos.x -= 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    opt = intro_ennemi_ctrl(obj, opt, rpg, house);
}

void update_text_pos(rpg_t *rpg, obj_t **obj, intro_t *intro)
{
    sfVector2f vect;

    if (rpg->quest_status == 0 || rpg->quest_status == 2) {
        vect = sfSprite_getPosition(obj[6]->sprite);
        vect.y -= 100;
    } else if ((rpg->quest_status >= 6 && rpg->quest_status <= 9)) {
        vect = sfSprite_getPosition(obj[8]->sprite);
        vect.y -= 50;
    } else {
        vect = sfSprite_getPosition(obj[0]->sprite);
        vect.x += 50;
        vect.y -= 50;
    }
    if (rpg->quest_status >= 11 && rpg->quest_status < 24) {
        if (rpg->quest_status == 11)
            vect = sfSprite_getPosition(obj[9]->sprite);
        else
            vect = sfSprite_getPosition(obj[8]->sprite);
        vect.y -= 70;
        vect.x -= 200;
    }
    if (sfSprite_getPosition(obj[0]->sprite).y <= 1900)
        update_intro_text(rpg, 1, intro);
    sfText_setPosition(intro->text, vect);
}

void intro_action(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intro)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        intro_control(obj, rpg, house);
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg, obj);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(rpg, obj, intro);
}