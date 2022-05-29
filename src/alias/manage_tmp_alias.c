/*
** EPITECH PROJECT, 2022
** manage_tmp_alias
** File description:
** alias tmp management
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "alias.h"
#include "my.h"

int create_alias(char **commands)
{
    if (my_write_in_file(ALIAS_TMP_FILE, "alias ") == -1)
        return -1;
    if (my_write_in_file(ALIAS_TMP_FILE, commands[1]) == -1)
        return -1;
    if (my_write_in_file(ALIAS_TMP_FILE, "=") == -1)
        return -1;
    for (int i = 2; commands[i] != NULL; i++) {
        if (my_write_in_file(ALIAS_TMP_FILE, commands[i]) == -1)
            return -1;
        if (commands[i + 1] != NULL)
            my_write_in_file(ALIAS_TMP_FILE, " ");
    }
    if (my_write_in_file(ALIAS_TMP_FILE, "\n") == -1)
        return -1;
    return 0;
}

void cat_the_alias(char **alias, int i, int *j)
{
    for (; *j < my_strlen(alias[i]) && alias[i][*j] != '='; *j += 1)
        my_putchar(alias[i][*j]);
    *j += 1;
    my_putstr("\t");
    for (; *j < my_strlen(alias[i]); *j += 1)
        my_putchar(alias[i][*j]);
    my_putstr("\n");
}

void print_alias_already_set(char *file)
{
    char *buffer = NULL;
    char **alias = NULL;
    int j = 0;

    buffer = file_to_buffer(file);
    if (buffer == NULL)
        return;
    alias = my_stwa_separator(buffer, "\n");
    if (alias == NULL) {
        free(buffer);
        return;
    }
    for (int i = 0; alias[i] != NULL; i++) {
        j = 6;
        if (strncmp(alias[i], "alias ", 6) == 0 && strlen(alias[i]) > 8) {
            cat_the_alias(alias, i, &j);
        }
    }
    my_freef("%s%t", buffer, alias);
    return;
}

int manage_tmp_alias(char **commands, shell_t *save)
{
    int cpt_arg = 0;
    char *path_shrc = my_strcat(my_get_line_env(save->env, "HOME="),
    "/.42shrc");

    if (path_shrc == NULL)
        return -1;
    for (; commands[cpt_arg] != NULL; cpt_arg++);
    if (cpt_arg == 1) {
        print_alias_already_set(ALIAS_TMP_FILE);
        print_alias_already_set(path_shrc);
        free(path_shrc);
        return 0;
    }
    free(path_shrc);
    if (cpt_arg == 2)
        return 0;
    if (search_alias_already_set(commands) == 1)
        return 0;
    else
        return create_alias(commands);
}
