/*
** EPITECH PROJECT, 2022
** parsing_alias
** File description:
** alias parse
*/

#include <stdio.h>
#include <stdlib.h>

#include "alias.h"
#include "my.h"

void cpt_nbr_arg(char ***alias, int i, int *cpt_arg)
{
    *cpt_arg = 0;
    for (int j = 0; alias[i][j] != NULL; j++)
        *cpt_arg += 1;
}

char ***my_alias_3d_array(char **file, int i, int cpt_nbr_alias)
{
    char ***alias = NULL;
    int cpt_arg = 0;

    alias = malloc(sizeof(char **) * (cpt_nbr_alias + 1));
    if (alias == NULL)
        return NULL;
    alias[cpt_nbr_alias] = NULL;
    for (int j = 0; j < cpt_nbr_alias && file[i] != NULL; i++, j++) {
        alias[j] = my_stwa_separator(file[i], " = \n\0");
        if (alias[j] == NULL)
            return NULL;
    }
    for (int i = 0; alias[i] != NULL; i++) {
        cpt_nbr_arg(alias, i, &cpt_arg);
        if (cpt_arg < 3) {
            my_free_3d_array(alias);
            return NULL;
        }
    }
    return alias;
}

char ***parsing_alias(char **file, int i)
{
    char ***alias = NULL;
    int cpt_nbr_alias = 0;

    for (int j = i; file[j] != NULL && my_strncmp(file[j], "alias", 5) == 0;
    j++, cpt_nbr_alias++);
    alias = my_alias_3d_array(file, i, cpt_nbr_alias);
    if (alias == NULL)
        return NULL;
    my_freef("%t", file);
    return alias;
}
