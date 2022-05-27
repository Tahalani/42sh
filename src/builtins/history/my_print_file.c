/*
** EPITECH PROJECT, 2022
** my_print_file
** File description:
** print a file
*/

#include <string.h>

#include "my.h"

void my_print_file(char const *filepath)
{
    char *str = my_file_in_str(filepath);
    char **tab = NULL;

    if (str == NULL)
        return;
    tab = my_stwa_separator(str, "\n");
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%d\t%s\n", i + 1, tab[i]);
    my_freef("%s%t", str, tab);
}

void my_print_file_n_last_line(char const *filepath, long long n)
{
    char *str = my_file_in_str(filepath);
    char **tab = NULL;
    int len_tab = 0;

    if (str == NULL)
        return;
    tab = my_stwa_separator(str, "\n");
    if (tab == NULL)
        return;
    len_tab = my_len_array(tab);
    if (n > len_tab) {
        my_print_file(filepath);
        my_freef("%s%t", str, tab);
        return;
    }
    for (int i = len_tab - n; (i >= 0 && i < len_tab) || tab[i] != NULL; i++)
        my_printf("%d\t%s\n", i + 1, tab[i]);
    my_freef("%s%t", str, tab);
}
