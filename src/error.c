/*
** EPITECH PROJECT, 2022
** error
** File description:
** error handling
*/

#include "my.h"
#include "mysh.h"
#include <stddef.h>

int error(int const argc, char const *argv[], char const *env[])
{
    if (env == NULL || env[0] == NULL)
        return (-1);
    if (argc != 1) {
        my_puterr("error, incorrect arguments\n");
        return (-1);
    }
    (void)argv;
    return (0);
}
