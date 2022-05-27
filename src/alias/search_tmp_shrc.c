/*
** EPITECH PROJECT, 2022
** search_tmp_alias
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "alias.h"
#include "my.h"

static int cmp_alias_cmd(char *line, char **commands, shell_t *save)
{
    char **alias = my_stwa_separator(line, " = \n\0");
    char **new_commands;
    int cpt_arg_arg = 0;

    if (alias == NULL)
        return -1;
    for (; alias[cpt_arg_arg] != NULL; cpt_arg_arg++);
    if (cpt_arg_arg < 3) {
        my_free_array(alias);
        return -1;
    }
    if (strcmp(commands[0], alias[1]) == 0) {
        new_commands = my_malloc_alias_array(commands, alias);
        if (new_commands == NULL)
            return -1;
        manage_commands(new_commands, save);
        my_freef("%t%t", new_commands, alias);
    } else {
        my_freef("%t", alias);
        return -1;
    }
}

int parsing_tmp_shrc(char **file, char **commands, shell_t *save)
{
    int ret_val = -1;

    for (int i = 0; file[i] != NULL; i++) {
        if (strncmp(file[i], "alias", 5) == 0 && strlen(file[i]) > 8)
            ret_val = cmp_alias_cmd(file[i], commands, save);
        if (ret_val == 0) {
            my_free_array(file);
            return 0;
        }
    }
    my_free_array(file);
    return -1;
}

int search_in_tmp_shrc(char **commands, shell_t *save)
{
    char **file;
    char *buffer = file_to_buffer("/tmp/.42shrc");

    if (buffer == NULL)
        return -1;
    file = my_stwa_separator(buffer, "\n\0");
    free(buffer);
    if (file == NULL)
        return -1;
    return parsing_tmp_shrc(file, commands, save);
}