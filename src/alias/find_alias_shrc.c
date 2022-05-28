/*
** EPITECH PROJECT, 2022
** find_alias_shrc
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alias.h"
#include "my.h"

int verif_line_shrc(char **alias, int i)
{
    int cpt_equal = 0;

    for (int j = 0; alias[i][j] != 0; j++) {
        if (alias[i][j] == '=')
            cpt_equal++;
    }
    if (cpt_equal != 1 || strlen(alias[i]) < 9
    || alias[i][5] != ' ' || alias[i][6] == ' ')
        return -1;
    if (strchr(alias[i], '\'') != NULL || strchr(alias[i], '\'') != NULL)
        return -1;
    for (int j = 0; alias[i][j] != 0; j++) {
        if (alias[i][j] == '=' && (strchr(" \n\0", alias[i][j + 1]) != NULL
        || strchr(" \n\0", alias[i][j - 1]) != NULL))
            return -1;
    }
    return 0;
}

int alias_part(char **file, int i, char **commands, shell_t *save)
{
    char ***alias;
    int ret_val = 0;

    for (int j = 0; file[j] != NULL; j++) {
        if (strncmp(file[j], "alias", 5) == 0 &&
        verif_line_shrc(file, j) == -1) {
            my_freef("%t", file);
            return -1;
        }
    }
    alias = parsing_alias(file, i);
    if (alias == NULL)
        return -1;
    ret_val = cmp_alias_and_cmd(alias, commands, save);
    my_free_3d_array(alias);
    return ret_val;
}

static int parsing_shrc(char *buffer, char **commands, shell_t *save)
{
    char **file;

    if (strncmp(buffer, "# Welcome to our beautiful 42SHRC !!!\n", 37) != 0)
        return -1;
    if (strstr(buffer, "# Alias\n") == NULL || strstr(buffer, "alias") == NULL)
        return -1;
    file = my_stwa_separator(buffer, "\n");
    for (int i = 0; file[i] != NULL; i++) {
        if (strncmp(file[i], "alias", 5) == 0) {
            return (alias_part(file, i, commands, save));
        }
    }
    my_freef("%t", file);
    return 0;
}

int search_in_shrc(char **commands, shell_t *save)
{
    char *buffer;
    char *file_shrc = my_strcat(my_get_line_env(save->env, "HOME="),
    "/.42shrc");

    if (file_shrc == NULL)
        return -1;
    if (search_in_tmp_shrc(commands, save) == 0) {
        free(file_shrc);
        return 0;
    }
    buffer = file_to_buffer(file_shrc);
    if (buffer == NULL) {
        free(file_shrc);
        return -1;
    }
    if (parsing_shrc(buffer, commands, save) == -1) {
        my_freef("%s%s", buffer, file_shrc);
        return -1;
    }
    return my_freef("%s%s", buffer, file_shrc);;
}
