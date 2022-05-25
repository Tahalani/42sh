/*
** EPITECH PROJECT, 2022
** my_prompt
** File description:
** FreeKOSOVO
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "mysh.h"
#include "my.h"
#include "color.h"

void my_prompt(char **env)
{
    char str[4096];
    char *str2 = NULL;
    char **prompt = NULL;

    if (!isatty(0))
        return;
    getcwd(str, 4096);
    str2 = malloc(sizeof(char) * (len_array_1d(str) + 1));
    if (str == NULL || str2 == NULL)
        return;
    str2 = my_strcpy(str2, str);
    prompt = my_stwa_separator(str2, "/");
    my_printf("%s[%s%s%s@%s%s %s%s%s]%s$%s>%s ", yellow, green,
        my_get_line_env(env, "USER="), yellow, purple,
        my_get_line_env(env, "HOSTNAME="), red,
        prompt[my_len_array(prompt) - 1], yellow, cyan, yellow, white);
    my_freef("%s%t", str2, prompt);
}
