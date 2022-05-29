/*
** EPITECH PROJECT, 2022
** my_getenv
** File description:
** getenv
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char **my_getenv(char **env, char *str)
{
    char *path = my_get_line_env(env, str);
    if (path == NULL)
        return (NULL);
    return (my_stwa_separator(my_get_line_env(env, str), ":"));
}
