/*
** EPITECH PROJECT, 2022
** ctrl_c
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <unistd.h>

#include "mysh.h"

void ctrl_c(UNUSED int signal)
{
    extern char **env_prompt;
    char c = '\n';

    write(1, &c, sizeof(char));
    my_prompt(env_prompt);
}
