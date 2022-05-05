/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** #FreeKOSOVO
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (str == NULL)
        return NULL;
    str = my_strcpy(str, src);
    return str;
}
