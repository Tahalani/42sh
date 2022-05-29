/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** echo
*/

#ifndef ECHO_H_
    #define ECHO_H_

    #include <stddef.h>
    #include "mysh.h"

int handle_echo_variable(char *commands, shell_t *save);
int parsing_echo_word(char **commands, char *word, char c);
int handle_backslash(char **commands, int i, size_t *j);
int verif_option_echo(char *commands);
int is_arg_hyphen_n(char *commands);
void echo_opt_maj_e(char **commands, shell_t *save);
void echo_opt_e(char **commands, shell_t *save);
void print_with_backslash(char **commands, int i, shell_t *save);
int verif_solo_quote(char **commands);
void print_simple_case(char *commands, shell_t *save);
int error(int const argc, char const *argv[], char const *env[]);

#endif/* !ECHO_H_ */
