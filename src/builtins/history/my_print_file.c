/*
** EPITECH PROJECT, 2022
** my_print_file
** File description:
** print a file
*/

#include "my.h"
#include <string.h>

void my_print_file(char const *filepath)
{
    char *str = my_file_in_str(filepath);

    if (str == NULL)
        return;
    my_printf("%s", str);
    my_freef("%s", str);
}
