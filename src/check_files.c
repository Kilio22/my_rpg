/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_files
*/

#include <stdio.h>
#include <dirent.h>
#include "rpg.h"

static char **my_realloc_array(char **tab, char *to_add)
{
    size_t len = my_tab_len(tab) + 2;
    char **new = malloc(sizeof(char *) * len);
    size_t i = 0;

    if (!new || !to_add)
        return NULL;
    for (; tab[i]; i++)
        new[i] = tab[i];
    new[i++] = to_add;
    new[i] = NULL;
    free(tab);
    return new;
}

static char **load_file(FILE *stream)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n_read = 0;
    size_t i = 0;
    char **tab = malloc(sizeof(char *) * 1);

    if (!stream || !tab)
        return NULL;
    tab[0] = NULL;
    while ((n_read = getline(&line, &len, stream)) != -1) {
        if (line[n_read - 1] == '\n')
            line[n_read - 1] = '\0';
        tab = my_realloc_array(tab, my_strdup(line));
        if (!tab)
            return NULL;
        i++;
    }
    if (i != 87)
        return NULL;
    return tab;
}

static int check_open(char **tab)
{
    FILE *stream;

    for (int i = 0; tab[i]; i++) {
        stream = fopen(tab[i], "r");
        if (!stream)
            return -1;
        fclose(stream);
    }
    return 0;
}

static int check_env(char **env)
{
    for (size_t i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "DISPLAY", 7) == 0)
            return 0;
    }
    return -1;
}

int check_files(char **env)
{
    DIR *dir = opendir("./assets");
    char **tab = NULL;
    FILE *stream;

    if (!dir)
        return -1;
    closedir(dir);
    stream = fopen(".fp", "r");
    if (!stream)
        return -1;
    tab = load_file(stream);
    fclose(stream);
    if (!tab)
        return -1;
    if (check_open(tab) == -1)
        return -1;
    if (check_env(env) == -1)
        return -1;
    return 0;
}