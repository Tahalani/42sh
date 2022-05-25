/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirection_left
*/

#include <stdlib.h>
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

void fd_function_manipulation(char const *command,
    int fd, char *after_red, shell_t *save)
{
    char **commands = NULL;
    int fd_tmp;

    fd_tmp = dup(0);
    dup2(fd, 0);
    commands = my_str_to_word_array(command);
    if (commands == NULL)
        return;
    manage_commands(commands, save);
    my_freef("%t%s%f", commands, after_red, fd);
    dup2(fd_tmp, 0);
}

void launch_redirect_left(char const *command,
    char const *direction, shell_t *save)
{
    char *after_red = my_clean_str(direction);
    int fd;

    if (after_red == NULL)
        return;
    fd = open(after_red, O_RDONLY);
    if (fd == -1)
        return;
    fd_function_manipulation(command, fd, after_red, save);
}

static int init_value_double_left(shell_t *save,
    char *word_after_redirection, int fd)
{
    save->status = 0;
    free(save->str);
    save->str = NULL;
    if (word_after_redirection == NULL)
        return (-1);
    fd = open("tmp_left", O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0666);
    if (fd == -1)
        return (-1);
    my_putstr("? ");
    return (fd);
}

void launch_double_redirect_left(char const *command,
    char const *direction, shell_t *save)
{
    char *word_after_redirection = my_clean_str(direction);
    int fd = 0;
    size_t size;

    fd = init_value_double_left(save, word_after_redirection, fd);
    if (fd == -1)
        return;
    while (getline(&save->str, &size, stdin) > 0) {
        save->str[strlen(save->str) - 1] = '\0';
        if (strcmp(save->str, word_after_redirection) == 0)
            break;
        write(fd, save->str, strlen(save->str));
        write(fd, "\n", 1);
        my_putstr("? ");
    }
    close(fd);
    fd = open("tmp_left", O_RDONLY);
    fd_function_manipulation(command, fd, word_after_redirection, save);
    remove("tmp_left");
}

char **manage_redirection_left(char const *commands,
    shell_t *save, char **command)
{
    command = my_stwa_separator(commands, "<\n");
    if (command == NULL ||
    handly_error_redirection(command, commands) == -1)
        return (NULL);
    if (strstr(commands, "<<") != NULL) {
        launch_double_redirect_left(command[0], command[1], save);
    }
    else if (strstr(commands, "<") != NULL)
        launch_redirect_left(command[0], command[1], save);
    return (command);
}
