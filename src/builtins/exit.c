/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** exit
*/

#include <string.h>
#include <stdlib.h>

#include "my.h"
#include "mysh.h"

int error_exit(char **commands)
{
    if (my_len_array(commands) > 2) {
        my_puterr("exit: Expression Syntax.\n");
        return (-1);
    }
    if (my_len_array(commands) == 2) {
        if (my_str_isnum(commands[1]) == 0) {
            my_puterr("exit: Badly formed number.\n");
            return (-1);
        }
    }
    return (0);
}

int my_exit(char **commands, shell_t *save)
{
    if (error_exit(commands) == -1)
        return (-1);
    my_putstr("exit\n");
    save->status = 1;
    if (commands[1] != NULL)
        save->return_value = my_getnbr(commands[1]);
    else
        save->return_value = 0;
    return (0);
}
