/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirection_left
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "mysh.h"
#include "my.h"

void launch_redirect_left(char const *command,
    char const *direction, shell_t *save)
{
    char *duplicate = my_clean_str(direction);
    int fd;
    char **commands = NULL;
    int fd_tmp;

    if (duplicate == NULL)
        return;
    fd = open(duplicate, O_WRONLY | O_APPEND, 00666);
    if (fd == -1)
        return;
    fd_tmp = dup(1);
    dup2(fd, 1);
    commands = my_str_to_word_array(command);
    if (commands == NULL)
        return;
    manage_commands(commands, save);
    my_freef("%t%s%f", commands, duplicate, fd);
    dup2(fd_tmp, 1);
}
