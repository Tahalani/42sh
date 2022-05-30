/*
** EPITECH PROJECT, 2022
** my_prompt
** File description:
** prompt file
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "my.h"
#include "mysh.h"
#include "color.h"

void my_prompt(char **env)
{
    char filepath[4096];
    char *tmp = NULL;
    char **prompt = NULL;
    char *user = my_get_line_env(env, "USER=");
    char *hostname = my_get_line_env(env, "HOSTNAME=");

    if (!isatty(INPUT))
        return;
    getcwd(filepath, 4096);
    tmp = malloc(sizeof(char) * (len_array_1d(filepath) + 1));
    if (filepath == NULL || tmp == NULL)
        return;
    tmp = my_strcpy(tmp, filepath);
    prompt = my_stwa_separator(tmp, "/");
    my_printf("%s[%s%s%s@%s%s %s%s%s]%s$%s>%s ", YELLOW, GREEN,
        user == NULL ? "user" : user, YELLOW, PURPLE,
        hostname == NULL ? "hostname" : hostname, RED,
        prompt[my_len_array(prompt) - 1], YELLOW, CYAN, YELLOW, WHITE);
    my_freef("%s%t", tmp, prompt);
}

int manage_other_separator_two(char *commands, shell_t *save, int check)
{
    if ((my_char_is_in_str(commands, '>') == 1 ||
    my_char_is_in_str(commands, '<') == 1) && check == 0) {
        manage_redirection(commands, save);
        check = 1;
    } if (strstr(commands, "if") != NULL && check == 0) {
        manage_if(commands, save);
        check = 1;
    } if (my_char_is_in_str(commands, '|') == 1 && check == 0) {
        manage_pipe(commands, save);
        check = 1;
    }
    return (check);
}
