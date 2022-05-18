/*
** EPITECH PROJECT, 2022
** ctrl_c
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "color.h"
#include "mysh.h"

void ctrl_c(UNUSED int signal)
{
    my_putchar('\n');
    char str[4096];
    char *str2 = NULL;
    char **prompt = NULL;
    char const *os;

    getcwd(str, 4096);
    str2 = malloc(sizeof(char) * (len_array_1d(str) + 1));
    if (str == NULL || str2 == NULL)
        return;
    str2 = my_strcpy(str2, str);
    prompt = my_stwa_separator(str2, "/");
    os = "fedora";
    my_printf("%s[%s%s%s@%s%s %s%s%s]%s$%s>%s ", yellow, green,
        "user", yellow, purple, os, red,
        prompt[my_len_array(prompt) - 1], yellow, cyan, yellow, white);
    my_freef("%s%t", str2, prompt);
}
