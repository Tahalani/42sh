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
#include <signal.h>
#include <stdio.h>
#include <string.h>

#include "mysh.h"
#include "my.h"

void launch_redirect_left(char const *command,
    char const *direction, shell_t *save)
{
    char *after_red = my_clean_str(direction);
    int fd;
    char **commands = NULL;
    int fd_tmp;

    if (after_red == NULL)
        return;
    fd = open(after_red, O_RDONLY);
    if (fd == -1)
        return;
    fd_tmp = dup(0);
    dup2(fd, 0);
    commands = my_str_to_word_array(command);
    if (commands == NULL)
        return;
    manage_commands(commands, save);
    my_freef("%t%s%f", commands, after_red, fd);
    dup2(fd_tmp, 0);
}

void launch_double_redirect_left(char const *direction, shell_t *save)
{
    char *after_red = my_clean_str(direction);
    save->str = NULL;
    size_t size;
    save->status = 0;

    if (after_red == NULL)
        return;
    signal(SIGINT, ctrl_c);
    my_putstr("? ");
    while (getline(&save->str, &size, stdin) > 0) {
        save->str[strlen(save->str) - 1] = '\0';
        if (strcmp(save->str, after_red) == 0)
            break;
        my_putstr("? ");
    }
}
