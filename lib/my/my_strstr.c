/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <stddef.h>

char *my_strdup(char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);

char *my_strstr(char const *str, char const *to_find)
{
    char *dup = my_strdup(str);
    char *tmp = dup;
    int i = 0;

    while (*dup != '\0') {
        if (*dup == *to_find && my_strncmp(to_find,
            dup, my_strlen(to_find)) == 0)
            break;
        dup++;
        i++;
    }
    if (*dup == '\0') {
        free(tmp);
        return NULL;
    }
    free(tmp);
    return ((char *)str + i);
}
