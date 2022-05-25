/*
** EPITECH PROJECT, 2022
** if_alias_ll.c
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "alias_array.h"
#include "my.h"

static char **mem_alloc_2d_array(int nb_rows)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[nb_rows] = NULL;
    return arr;
}

char **my_malloc_ll_array(char **commands)
{
    int cpt_arg = 0;
    char **new_commands;
    char *av[3] = {"ls", "-l", NULL};

    for (; commands[cpt_arg] != NULL; cpt_arg++);
    new_commands = mem_alloc_2d_array((cpt_arg + 2));
    if (new_commands == NULL)
        return NULL;
    for (int i = 0; i < 2; i++) {
        new_commands[i] = strdup(av[i]);
        if (new_commands[i] == NULL)
            return NULL;
    }
    for (int i = 1; i < cpt_arg; i++) {
        new_commands[i + 1] = strdup(commands[i]);
        if (new_commands[i + 1] == NULL)
            return NULL;
    }
    return new_commands;
}

void execute2(char **new_commands, shell_t *save)
{
    char **bin = my_getenv(save->env, "PATH=");
    char *str2 = my_strcat("/", new_commands[0]);

    my_strcat_in_array(bin, str2);
    if (bin != NULL) {
        for (int i = 0; bin[i] != NULL; ++i)
            execve(bin[i], new_commands, save->env);
    }
    execve(new_commands[0], new_commands, save->env);
    my_puterr(new_commands[0]);
    my_puterr(": Command not found.\n");
    my_freef("%t%t%s", new_commands, bin, str2);
    exit(1);
}

int my_alias_ll(char **commands, shell_t *save)
{
    char **new_commands = my_malloc_ll_array(commands);

    if (new_commands == NULL)
        return -1;
    for (int i = 0; new_commands[i] != NULL; i++)
    {
        printf("contenu[%s]\n", new_commands[i]);
    }
    // execute2(new_commands, save);
    return 0;
}


int if_alias_ll(char **commands, shell_t *save)
{
    if (my_strcmp(commands[0], "ll") == 0) {
        save->return_value =
        my_alias_ll(commands, save) == -1 ? 1 : save->return_value;
        return (0);
    }
    return (1);
}
