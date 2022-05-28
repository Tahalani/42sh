/*
** EPITECH PROJECT, 2022
** print_var_exists
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <string.h>

#include "variables.h"
#include "my.h"

void cat_the_var(char **var, int i, int *j)
{
    for (*j = 4; *j < my_strlen(var[i]) && var[i][*j] != '='; *j += 1)
        my_putchar(var[i][*j]);
    *j += 1;
    my_putstr("\t");
    for (; *j < my_strlen(var[i]); *j += 1)
        my_putchar(var[i][*j]);
    my_putstr("\n");
}

void print_var_already_set(char *file)
{
    char *buffer;
    char **var;
    int j = 0;

    buffer = my_file_in_str(file);
    if (buffer == NULL)
        return;
    var = my_stwa_separator(buffer, "\n");
    if (var == NULL) {
        free(buffer);
        return;
    }
    for (int i = 0; var[i] != NULL; i++) {
        if (strncmp(var[i], "var ", 3) == 0 && strlen(var[i]) > 6)
            cat_the_var(var, i, &j);
    }
    my_freef("%s%t", buffer, var);
    return;
}
