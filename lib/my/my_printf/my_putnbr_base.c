/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_putnbr_base
*/

#include "../my.h"

int my_putnbr_base(int nb, char *base)
{
    int len_str = my_strlen(base);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    int a = nb % len_str;
    nb = nb / len_str;
    if (nb > 0)
        my_putnbr_base(nb, base);
    my_putchar(base[a]);
    return (nb);
}
