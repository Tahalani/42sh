/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_put_special
*/

#include <unistd.h>
#include "../my.h"

void put_space(char const *str, int i)
{
    if (str[i] < 10)
        my_putstr("00");
    else if (str[i] < 100)
        my_putchar('0');
}

int my_put_special(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            put_space(str, i);
            my_putnbr_base((int)str[i], "01234567");
        } else
            my_putchar(str[i]);
    }
    return (0);
}

int my_putchar_special(char c)
{
    if (c < 32 || c > 126) {
        my_putchar('\\');
        if (c < 10)
            my_putstr("00");
        else if (c < 100)
            my_putchar('0');
        my_putnbr_base((int)c, "01234567");
    } else
        my_putchar(c);
    return (0);
}
