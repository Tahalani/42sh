/*
** EPITECH PROJECT, 2022
** my_replace_in_tab
** File description:
** my_replace_in_tab
*/

#include <stddef.h>

static char **replace_char(char **tab, char const delete, char const new,
    int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == delete)
            tab[i][j] = new;
    }
    return (tab);
}

void my_replace_in_tab(char **tab,
    char const old_element, char const new_element)
{
    for (int i = 0; tab[i] != NULL; i++) {
        tab = replace_char(tab, old_element, new_element, i);
    }
}
