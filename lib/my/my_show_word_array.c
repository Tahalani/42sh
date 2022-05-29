/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** my_show_word_array
*/

#include <stddef.h>

void my_putstr(char const *src);
void my_putchar(char c);

void my_show_word_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}
