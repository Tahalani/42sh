/*
** EPITECH PROJECT, 2022
** get_line_tab
** File description:
** FreeKOSOVO
*/

#include <stddef.h>

int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);

int my_get_line_tab(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(tab[i], str, my_strlen(str)) == 0)
            return (i);
    }
    return (-1);
}
