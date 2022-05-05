/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include "mysh.h"
#include "my.h"

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
    my_printf("[%s@%s %s]$ ", "username", "os", prompt[my_len_array(prompt) - 1]);
    my_freef("%s%t", str2, prompt);
}

int myshell(shell_t *save)
{
    save->str = NULL;
    size_t size;
    save->status = 0;

    signal(SIGINT, ctrl_c);
    my_prompt();
    while (save->status == 0 && getline(&save->str, &size, stdin) > 0) {
        manage_separator(save);
        if (save->status == 1)
            break;
        my_prompt();
    }
    free(save->str);
    return (0);
}
