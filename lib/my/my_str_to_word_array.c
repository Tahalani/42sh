/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static int count_word(char const *str)
{
    int counter = 0;
    int size = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\\')
            i++;
        if ((my_char_is_alpha_num(str[i]) == 1) && i > 0 && str[i - 1] == '\\')
            i++;
        if (size < i)
            return (counter);
        if ((my_char_is_printable(str[i]) == 1) &&
        (my_char_is_printable(str[i + 1]) == 0)) {
            counter++;
        }
    }
    return (counter);
}

static char **mem_alloc_2d_array(int nb_rows)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[nb_rows] = NULL;
    return arr;
}

static int size_word(char const *str, int i)
{
    int k = 0;

    while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' &&
    str[i] != '\0') {
        i++;
        k++;
    }
    return (k);
}

char **my_str_to_word_array(char const *str)
{
    int nb_word = count_word(str);
    char **tab = mem_alloc_2d_array(nb_word);
    int size = 0;
    int i = 0;

    if (tab == NULL)
        return NULL;
    for (int j = 0; j < nb_word; j++) {
        for (; str[i] == ' ' || str[i] == '\n' || str[i] == '\t'; i++);
        size = size_word(str, i);
        tab[j] = malloc(sizeof(char) * (size + 1));
        if (tab[j] == NULL)
            return NULL;
        my_strncpy(tab[j], &str[i], size);
        i += size;
    }
    return (tab);
}
