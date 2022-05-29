/*
** EPITECH PROJECT, 2022
** cmp_alias_and_cmd
** File description:
** alias cmp
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "alias.h"
#include "my.h"
#include "mysh.h"

static char **mem_alloc_2d_array(int nb_rows)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[nb_rows] = NULL;
    return arr;
}

static char **create_the_array(char **commands, char **alias, int *cpt_arg,
    int *cpt_alias_arg)
{
    char **new_commands = NULL;

    for (int i = 1; commands[i] != NULL; *cpt_arg += 1, i++);
    for (int i = 2; alias[i] != NULL; i++, *cpt_alias_arg += 1);
    new_commands = mem_alloc_2d_array((*cpt_arg + *cpt_alias_arg));
    return new_commands;
}

char **my_malloc_alias_array(char **commands, char **alias)
{
    int cpt_arg = 0;
    int cpt_alias_arg = 0;
    char **new_commands = NULL;
    int j = 0;

    new_commands = create_the_array(commands, alias, &cpt_arg, &cpt_alias_arg);
    if (new_commands == NULL)
        return NULL;
    for (int i = 0; i < cpt_alias_arg; i++) {
        new_commands[i] = strdup(alias[i + 2]);
        if (new_commands[i] == NULL)
            return NULL;
    }
    j = cpt_arg;
    for (int i = cpt_alias_arg; i < cpt_alias_arg + cpt_arg; i++, j++) {
        new_commands[i] = strdup(commands[j]);
        if (new_commands[i] == NULL)
            return NULL;
    }
    return new_commands;
}

int exec_alias(char **commands, shell_t *save, char **alias)
{
    char **new_commands = my_malloc_alias_array(commands, alias);

    if (new_commands == NULL)
        return -1;
    manage_commands(new_commands, save);
    my_freef("%t", new_commands);
    return 0;
}

int cmp_alias_and_cmd(char ***alias, char **commands, shell_t *save)
{
    for (int i = 0; alias[i] != NULL; i++) {
        if (strcmp(commands[0], alias[i][1]) == 0) {
            exec_alias(commands, save, alias[i]);
            return 0;
        }
    }
    return (-1);
}
