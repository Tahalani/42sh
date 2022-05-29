/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_stwa_separator
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "my.h"

static int count_word_2(char const *str, char const *separator)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((!my_char_is_in_str(separator, str[i]))
            && (my_char_is_in_str(separator, str[i + 1])
            || str[i + 1] == '\0'))
            counter++;
    }
    return (counter);
}

static char **mem_alloc_2d_array_2(int nb_rows)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));

    if (arr == NULL)
        return NULL;
    arr[nb_rows] = NULL;
    return arr;
}

static int size_word_2(char const *str, int i, char const *separator)
{
    int k = 0;

    while (!my_char_is_in_str(separator, str[i]) && str[i] != '\0') {
        i++;
        k++;
    }
    return (k);
}

char **my_stwa_separator(char const *str, char const *separator)
{
    int nb_word = count_word_2(str, separator);
    char **tab = mem_alloc_2d_array_2(nb_word);
    int size = 0;
    int i = 0;

    if (tab == NULL)
        return NULL;
    for (int j = 0; j < nb_word; j++) {
        for (; my_char_is_in_str(separator, str[i]); i++);
        size = size_word_2(str, i, separator);
        tab[j] = malloc(sizeof(char) * (size + 1));
        if (tab[j] == NULL)
            return NULL;
        tab[j] = my_strncpy(tab[j], &str[i], size);
        i += size;
    }
    return (tab);
}
