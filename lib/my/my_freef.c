/*
** EPITECH PROJECT, 2022
** my_freef
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"

void my_freef_2(int *i, va_list list, char *s)
{
    if (s[*i] == '%' && s[*i + 1] == 's') {
        free(va_arg(list, char *));
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 't') {
        my_free_array(va_arg(list, char **));
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'f') {
        close(va_arg(list, int));
        *i += 2;
    }
}

int my_freef(char *s, ...)
{
    va_list list;
    int a;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        a = i;
        my_freef_2(&i, list, s);
        if (s[i] == '\0')
            break;
        if (s[i] == '%' && a != i)
            i--;
    }
    va_end(list);
    return (0);
}
