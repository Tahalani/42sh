/*
** EPITECH PROJECT, 2022
** redirection
** File description:
** FreeKOSOVO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "mysh.h"
#include "my.h"
#include "redirection.h"

int handly_error_redirection(char **command, char const *commands)
{
    if (my_len_array(command) < 2) {
        my_puterr("Missing name for redirect.\n");
        my_freef("%t", command);
        return -1;
    }
    (void)commands;
    return 0;
}

void manage_redirection(char const *commands, shell_t *save)
{
    char **command = NULL;

    if (my_char_is_in_str(commands, '>') == 1) {
        command = manage_redirection_right(commands, save, command);
        if (command == NULL)
            return;
    }
    if (my_char_is_in_str(commands, '<') == 1) {
        command = manage_redirection_left(commands, save, command);
        if (command == NULL)
            return;
    }
    my_free_array(command);
}
