/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_putlong
*/

#include "../my.h"

int my_putlong(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb <= 9)
        my_putchar(nb + '0');
    else {
        my_putlong(nb / 10);
        nb = nb % 10;
        my_putchar(nb + '0');
    }
    return 0;
}
