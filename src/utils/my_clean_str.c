/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_clean_str
*/

#include <stdlib.h>
#include "my.h"

char *my_clean_str(char const *str)
{
    char **new = my_str_to_word_array(str);
    char *result = NULL;

    if (new == NULL)
        return NULL;
    result = my_strdup(new[0]);
    if (result == NULL)
        return NULL;
    my_free_array(new);
    return result;
}
