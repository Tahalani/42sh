/*
** EPITECH PROJECT, 2021
** my_putchar_error
** File description:
** #FreeKOSOVO
*/

#include <unistd.h>

void my_putchar_error(char const c)
{
    write(2, &c, 1);
}
