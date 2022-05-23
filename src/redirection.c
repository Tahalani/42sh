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

#include "mysh.h"
#include "my.h"

char *my_clean_str(char const *str)
{
    char **new = my_str_to_word_array(str);
    char *result = NULL;

    if (new == NULL)
        return NULL;
    result = my_strdup(new[0]);
    if (result == NULL)
        return NULL;
    my_free_array(new);
    return result;
}

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

    command = my_stwa_separator(commands, ">\n");
    if (command == NULL || handly_error_redirection(command, commands) == -1)
        return;
    if (my_strstr(commands, ">>") != NULL)
        launch_double_redirect(command[0], command[1], save);
    else if (my_strstr(commands, ">") != NULL)
        launch_redirect(command[0], command[1], save);
    else
        launch_redirect_left(command[0], command[1], save);
    my_free_array(command);
}
