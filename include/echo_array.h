/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** echo_array
*/

#ifndef ECHO_ARRAY_H_
    #define ECHO_ARRAY_H_

    #define NBR_BACKSLASH 7

    #include "mysh.h"
    #include <stdio.h>

int if_backlash_t(char **commands, int i, size_t *j);
int if_backlash_a(char **commands, int i, size_t *j);
int if_backlash_b(char **commands, int i, size_t *j);
int if_backlash_v(char **commands, int i, size_t *j);
int if_backlash_f(char **commands, int i, size_t *j);
int if_backlash_r(char **commands, int i, size_t *j);
int if_backlash_n(char **commands, int i, size_t *j);

static int (*ECHO_ARRAY[]) (char **commands, int i, size_t *j) = {
    if_backlash_t,
    if_backlash_a,
    if_backlash_b,
    if_backlash_v,
    if_backlash_f,
    if_backlash_r,
    if_backlash_n
};

#endif/* !ECHO_ARRAY_H_ */
