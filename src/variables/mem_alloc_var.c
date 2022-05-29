/*
** EPITECH PROJECT, 2022
** search_variables
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "variables.h"
#include "my.h"

char ***my_var_3d_array(char **file, int i, int cpt_nbr_var)
{
    char ***var = NULL;
    int cpt_arg = 0;

    var = malloc(sizeof(char **) * (cpt_nbr_var + 1));
    if (var == NULL)
        return NULL;
    var[cpt_nbr_var] = NULL;
    for (int j = 0; j < cpt_nbr_var && file[i] != NULL; i++, j++)
        var[j] = my_stwa_separator(file[i], " = \n\0");
    for (int i = 0; var[i] != NULL; i++) {
        for (int j = 0; var[i][j] != NULL; j++)
            cpt_arg++;
        if (cpt_arg < 2) {
            my_free_3d_array(var);
            return NULL;
        }
        cpt_arg = 0;
    }
    return var;
}

static char **mem_alloc_2d_array(int nb_rows)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[nb_rows] = NULL;
    return arr;
}

static char **create_the_var_array(char **commands, char **var, int *cpt_arg,
int *cpt_var_arg)
{
    char **new_commands = NULL;

    for (int i = 1; commands[i] != NULL; *cpt_arg += 1, i++);
    for (int i = 2; var[i] != NULL; i++, *cpt_var_arg += 1);
    new_commands = mem_alloc_2d_array((*cpt_arg + *cpt_var_arg));
    return new_commands;
}

char **my_malloc_var_array(char **commands, char **var)
{
    int cpt_arg = 0;
    int cpt_var_arg = 0;
    char **new_commands = NULL;
    int j = 0;

    new_commands = create_the_var_array(commands, var, &cpt_arg, &cpt_var_arg);
    if (new_commands == NULL)
        return NULL;
    for (int i = 0; i < cpt_var_arg; i++) {
        new_commands[i] = strdup(var[i + 2]);
        if (new_commands[i] == NULL)
            return NULL;
    }
    j = cpt_arg;
    for (int i = cpt_var_arg; i < cpt_var_arg + cpt_arg; i++, j++) {
        new_commands[i] = strdup(commands[j]);
        if (new_commands[i] == NULL)
            return NULL;
    }
    return new_commands;
}

char ***parsing_var(char **file, int i)
{
    char ***var = NULL;
    int cpt_nbr_var = 0;

    for (int j = i; file[j] != NULL && my_strncmp(file[j], "var", 3) == 0;
    j++, cpt_nbr_var++);
    var = my_var_3d_array(file, i, cpt_nbr_var);
    if (var == NULL)
        return NULL;
    my_freef("%t", file);
    return var;
}
