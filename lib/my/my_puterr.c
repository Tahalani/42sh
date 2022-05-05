/*
** EPITECH PROJECT, 2021
** my_puterr
** File description:
** #FreeKOSOVO
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
}
