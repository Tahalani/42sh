/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirection_right
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

void launch_redirect(char const *command, char const *direction, shell_t *save)
{
    char *duplicate = my_clean_str(direction);
    int fd;
    char **commands = NULL;
    int fd_tmp;

    if (duplicate == NULL)
        return;
    fd = open(duplicate, O_CREAT | O_WRONLY | O_TRUNC, 00666);
    if (fd == -1)
        return;
    free(duplicate);
    fd_tmp = dup(1);
    dup2(fd, 1);
    commands = my_str_to_word_array(command);
    if (commands == NULL)
        return;
    manage_commands(commands, save);
    my_free_array(commands);
    close(fd);
    dup2(fd_tmp, 1);
}

void launch_double_redirect(char const *command,
    char const *direction, shell_t *save)
{
    char *duplicate = my_clean_str(direction);
    int fd;
    char **commands = NULL;
    int fd_tmp;

    if (duplicate == NULL)
        return;
    fd = open(duplicate, O_CREAT | O_WRONLY | O_APPEND, 00666);
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

char **manage_redirection_right(char const *commands,
    shell_t *save, char **command)
{
    command = my_stwa_separator(commands, ">\n");
    if (command == NULL ||
    handly_error_redirection(command, commands) == -1)
        return NULL;
    if (strstr(commands, ">>") != NULL)
        launch_double_redirect(command[0], command[1], save);
    else if (strstr(commands, ">") != NULL)
        launch_redirect(command[0], command[1], save);
    return (command);
}
