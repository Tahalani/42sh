/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** if_array
*/

#ifndef IF_ARRAY_H_
    #define IF_ARRAY_H_

    #include "if.h"
    #include "my.h"

static const int flag_nbr = 5;

static int (*OPT_FUNC[]) (char const *, char **, shell_t *save) = {
    if_flag_e_a,
    if_flag_d,
    if_flag_e_a,
    if_flag_r,
    if_flag_w
};

static const char *OPT_ARRAY[] = {
    "-a",
    "-d",
    "-e",
    "-r",
    "-w"
};

#endif/* !IF_ARRAY_H_ */
