/*
** EPITECH PROJECT, 2021
** echo
** File description:
** FreeKOSOVO
*/

#ifndef echo
    #define echo

    #include <stddef.h>

void handle_backslash(char **commands, int i, size_t *j);
int verif_option_echo(char *commands);
int is_arg_hyphen_n(char *commands);
void echo_opt_maj_e(char **commands);
void echo_opt_e(char **commands);
void print_with_backslash(char **commands, int i);
int verif_solo_quote(char **commands);
void print_simple_case(char *commands);
int error(int const argc, char const *argv[], char const *env[]);

#endif/* !echo */
