/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** #FreeKOSOVO
*/

#include <unistd.h>

void my_putchar(char const c)
{
    write(1, &c, 1);
}