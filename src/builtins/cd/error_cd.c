/*
** EPITECH PROJECT, 2022
** error_cd
** File description:
** FreeKOSOVO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int error_cd(char **commands)
{
    struct stat buff;

    if (my_len_array(commands) > 2) {
        my_puterr("cd: Too many arguments.\n");
        return (-1);
    }
    if (my_len_array(commands) == 2 && my_strcmp(commands[1], "-") != 0) {
        if (stat(commands[1], &buff) == -1) {
            my_puterr(commands[1]);
            my_puterr(": No such file or directory.\n");
            return (-1);
        }
        if (gettype(buff) != 'd') {
            my_puterr(commands[1]);
            my_puterr(": Not a directory.\n");
            return (-1);
        }
    }
    return (0);
}
