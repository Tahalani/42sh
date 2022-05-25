/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** redirection
*/

#ifndef REDIRECTION_H_
    #define REDIRECTION_H_
    #define TMP_FILE "tmp_redirection"
    #include "mysh.h"


void launch_redirect(char const *command,
    char const *direction, shell_t *save);

void launch_double_redirect(char const *command,
    char const *direction, shell_t *save);

void launch_redirect_left(char const *command,
    char const *direction, shell_t *save);

int handly_error_redirection(char **command, char const *commands);

void manage_redirection(char const *commands, shell_t *save);

void launch_double_redirect_left(char const *command,
    char const *direction, shell_t *save);

char **manage_redirection_left(char const *commands,
    shell_t *save, char **command);

char **manage_redirection_right(char const *commands,
    shell_t *save, char **command);

#endif/* !REDIRECTION_H_ */
