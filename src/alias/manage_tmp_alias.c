/*
** EPITECH PROJECT, 2022
** manage_tmp_alias
** File description:
** FreeKOSOVO
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

void print_alias_already_set(char *file)
{
    char *buffer;
    char **alias;
 
    buffer = file_to_buffer(file);
    if (buffer == NULL)
        return;
    alias = my_stwa_separator(buffer, "\n");
    if (alias == NULL) {
        free(buffer);
        return;
    }
    for (int i = 0; alias[i] != NULL; i++) {
        if (strncmp(alias[i], "alias ", 6) == 0 && strlen(alias[i]) > 8) {
            my_putstr(alias[i] + 6);
            my_putchar('\n');
        }
    }
    my_freef("%s%t", buffer, alias);
    return;
}

int manage_tmp_alias(char **commands, shell_t *save)
{
    int cpt_arg = 0;
    char *path_shrc = my_strcat(my_get_line_env(save->env, "HOME="), "/.42shrc");

    for (; commands[cpt_arg] != NULL; cpt_arg++);
    if (cpt_arg == 1) {
        print_alias_already_set(path_shrc);
        print_alias_already_set(ALIAS_TMP_FILE);
        free(path_shrc);
        return 0;
    }
    if (cpt_arg == 2)
        return 0;
    if (search_alias_already_set(commands) == 1)
        return 0;
    else
        return create_alias(commands);
}
