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

int manage_if(char const *commands, shell_t *save);

typedef int if_flags_t(const char *commands,
    char **commands_array, shell_t *save);

if_flags_t if_flag_e_a;

if_flags_t if_flag_b;

if_flags_t if_flag_c;

if_flags_t if_flag_d;

if_flags_t if_flag_f;

if_flags_t if_flag_r;

if_flags_t if_flag_w;

if_flags_t if_flag_x;

#endif/* !IF_H_ */
