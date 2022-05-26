/*
** EPITECH PROJECT, 2021
** echo
** File description:
** FreeKOSOVO
*/

#ifndef echo
    #define echo

    #include <stddef.h>
    #include "mysh.h"

int parsing_echo_word(char **commands, char *word, char c);
void handle_backslash(char **commands, int i, size_t *j);
int verif_option_echo(char *commands);
int is_arg_hyphen_n(char *commands);
void echo_opt_maj_e(char **commands, shell_t *save);
void echo_opt_e(char **commands, shell_t *save);
void print_with_backslash(char **commands, int i, shell_t *save);
int verif_solo_quote(char **commands);
void print_simple_case(char *commands, shell_t *save);
int error(int const argc, char const *argv[], char const *env[]);

#endif/* !echo */
