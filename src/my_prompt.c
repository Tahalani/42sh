/*
** EPITECH PROJECT, 2022
** my_prompt
** File description:
** FreeKOSOVO
*/

#include <unistd.h>
#include <stdlib.h>

#include "mysh.h"
#include "my.h"
#include "color.h"

// TODO username, os and user rigth !
void my_prompt(void)
{
    char str[4096];
    char *str2 = NULL;
    char **prompt = NULL;

    getcwd(str, 4096);
    str2 = malloc(sizeof(char) * (len_array_1d(str) + 1));
    if (str == NULL || str2 == NULL)
        return;
    str2 = my_strcpy(str2, str);
    prompt = my_stwa_separator(str2, "/");
    my_printf("%s[%s%s%s@%s%s %s%s%s]%s$%s>%s ", yellow, green,
        "username", yellow, purple, "os", red,
        prompt[my_len_array(prompt) - 1], yellow, cyan, yellow, white);
    my_freef("%s%t", str2, prompt);
}
