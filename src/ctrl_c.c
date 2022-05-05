/*
** EPITECH PROJECT, 2022
** ctrl_c
** File description:
** FreeKOSOVO
*/

#include "my.h"

void ctrl_c(int sig)
{
    my_putstr("\n> ");
    (void)sig;
}
