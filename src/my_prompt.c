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
    char filepath[4096];
    char *tmp = NULL;
    char **prompt = NULL;

    if (!isatty(INPUT))
        return;
    getcwd(filepath, 4096);
    tmp = malloc(sizeof(char) * (len_array_1d(filepath) + 1));
    if (filepath == NULL || tmp == NULL)
        return;
    tmp = my_strcpy(tmp, filepath);
    prompt = my_stwa_separator(tmp, "/");
    my_printf("%s[%s%s%s@%s%s %s%s%s]%s$%s>%s ", yellow, green,
        my_get_line_env(env, "USER="), yellow, purple,
        my_get_line_env(env, "HOSTNAME="), red,
        prompt[my_len_array(prompt) - 1], yellow, cyan, yellow, white);
    my_freef("%s%t", tmp, prompt);
}
