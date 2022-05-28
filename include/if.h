/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** if
*/

#ifndef IF_H_
    #define IF_H_

    #include "my.h"

int launch_if_getline(shell_t *save, char **command_after_comma);

int if_flag_e_a(char const *commands, char **command_array, shell_t *save);

int if_flag_b(char const *commands, char **command_array, shell_t *save);

int if_flag_c(char const *commands, char **command_array, shell_t *save);

int if_flag_d(char const *commands, char **command_array, shell_t *save);

int if_flag_f(char const *commands, char **command_array, shell_t *save);

int if_flag_r(char const *commands, char **command_array, shell_t *save);

int if_flag_w(char const *commands, char **command_array, shell_t *save);

int manage_if(char const *commands, shell_t *save);

#endif/* !IF_H_ */
