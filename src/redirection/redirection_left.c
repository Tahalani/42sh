/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirection_left
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "mysh.h"
#include "my.h"
#include "redirection.h"

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
    char *word_after_redirection = my_clean_str(direction);
    save->str = NULL;
    size_t size;
    save->status = 0;

    if (word_after_redirection == NULL)
        return;
    signal(SIGINT, ctrl_c);
    my_putstr("? ");
    while (getline(&save->str, &size, stdin) > 0) {
        save->str[strlen(save->str) - 1] = '\0';
        if (signal(SIGINT, ctrl_c))
            break;
        if (strcmp(save->str, word_after_redirection) == 0)
            break;
        my_putstr("? ");
    }
}

char **manage_redirection_left(char const *commands,
    shell_t *save, char **command)
{
    command = my_stwa_separator(commands, "<\n");
    if (command == NULL ||
    handly_error_redirection(command, commands) == -1)
        return (NULL);
    if (strstr(commands, "<<") != NULL)
        launch_double_redirect_left(command[1], save);
    else if (strstr(commands, "<") != NULL)
        launch_redirect_left(command[0], command[1], save);
    return (command);
}
