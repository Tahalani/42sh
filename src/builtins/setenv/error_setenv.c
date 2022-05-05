/*
** EPITECH PROJECT, 2022
** error_setenv
** File description:
** FreeKOSOVO
*/

#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "setenv.h"

static int check_parentheses(char **commands)
{
    int check = 0;
    for (int i = 0; commands[1][i] != '\0'; i++) {
        if (parentheses_2(commands, &check, i) == -1)
            return (-1);
    }
    if (check_second_bracket(check) == -1)
        return (-1);
    return (0);
}

static void resetenv(char ***env, char **commands)
{
    int line = my_get_line_tab(*env, commands[1]);
    char *new_str = NULL;
    char *result = NULL;

    new_str = my_strcat(commands[1], "=");
    if (new_str == NULL)
        return;
    result = my_strcat(new_str, commands[2]);
    free(new_str);
    free((*env)[line]);
    (*env)[line] = malloc(sizeof(char) * (my_strlen(result) + 1));
    if ((*env)[line] == NULL)
        return;
    (*env)[line] = my_strcpy((*env)[line], result);
    free(result);
}

int check_words(char **commands, char ***env)
{
    if (my_get_line_tab(*env, commands[1]) != -1) {
        if (my_len_array(commands) == 3)
            resetenv(env, commands);
        return (-1);
    }
    if (check_parentheses(commands) == -1)
        return (-1);
    for (int i = 0; commands[1][i] != '\0'; i++)
        if (my_char_is_alpha_num(commands[1][i]) == 0 &&
        commands[1][i] != '_') {
            my_puterr
            ("setenv: Variable name must contain alphanumeric characters.\n");
            return (-1);
        }
    return (0);
}

static int error_setenv2(char **commands, int *value)
{
    if (my_len_array(commands) > 3) {
        my_puterr("setenv: Too many arguments.\n");
        *value = 1;
        return (-1);
    }
    if (my_char_isalpha(commands[1][0]) == 0 && commands[1][0] != '_') {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        *value = 1;
        return (-1);
    }
    return (0);
}

int error_setenv(char **commands, char ***env, int *value)
{
    int a;
    if (my_len_array(commands) == 1) {
        my_show_word_array(*env);
        return (-1);
    }
    a = check_words(commands, env);
    if (a != 0) {
        if (a == -1)
            *value = 1;
        return (-1);
    } else if (error_setenv2(commands, value) == -1)
        return (-1);
    if (my_len_array(commands) == 3)
        return (1);
    return (0);
}
