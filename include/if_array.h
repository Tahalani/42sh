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

static int (*OPT_FUNC[]) (char const *, char **, shell_t *save) = {
    if_flag_e_a,
    if_flag_d,
    if_flag_e_a
};

static const char *OPT_ARRAY[] = {
    "-a",
    "-d",
    "-e"
};

#endif/* !IF_ARRAY_H_ */
