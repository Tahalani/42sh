/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strcapitalize
*/

#include <stdio.h>

int my_char_isalpha(char const c);

char *my_strcapitalize(char *str)
{
    if (my_char_isalpha(str[0]) == 1)
        str[0] = str[0] - 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (my_char_isalpha(str[i]) == 1 && my_char_isalpha(str[i - 1]) == 0)
            str[i] = str[i] - 32;
    }
    return (str);
}
