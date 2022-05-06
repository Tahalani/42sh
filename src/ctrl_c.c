/*
** EPITECH PROJECT, 2022
** ctrl_c
** File description:
** FreeKOSOVO
*/

#include "my.h"

void my_prompt(void);

void ctrl_c(int sig)
{
    my_putchar('\n');
    my_prompt();
    (void)sig;
}
