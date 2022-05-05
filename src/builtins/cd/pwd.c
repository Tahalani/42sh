/*
** EPITECH PROJECT, 2022
** pwd
** File description:
** FreeKOSOVO
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "mysh.h"
#include "builtins.h"
#include "my.h"

int len_array_1d(char const *arr)
{
    int i = 0;

    for (; my_char_is_printable(arr[i]) != 0; i++);
    return (i);
}

int load_pwd(char ***env)
{
    int i = my_get_line_tab(*env, "PWD");
    char str[4096];
    char *str2 = NULL;
    char *tmp = NULL;

    getcwd(str, 4096);
    str2 = malloc(sizeof(char) * (len_array_1d(str) + 1));
    if (str == NULL || str2 == NULL)
        return (-1);
    str2 = my_strcpy(str2, str);
    tmp = my_strdup("PWD=");
    if (tmp == NULL)
        return (-1);
    free((*env)[i]);
    (*env)[i] = my_strcat(tmp, str2);
    if ((*env)[i] == NULL)
        return (-1);
    free(tmp);
    free(str2);
    return (0);
}

static void create_oldpwd(char ***env)
{
    char *command = my_strdup("setenv OLDPWD");
    char **commands = NULL;
    int x = 0;

    if (command == NULL)
        return;
    commands = my_str_to_word_array(command);
    if (commands == NULL)
        return;
    *env = my_setenv(*env, commands, &x);
    free(command);
    my_free_array(commands);
    if (*env == NULL)
        exit(84);
}

int load_oldpwd(char ***env)
{
    int line_oldpwd = my_get_line_tab(*env, "OLDPWD=");
    char *str = my_get_line_env(*env, "PWD=");
    char *tmp = NULL;

    if (str == NULL)
        return (-1);
    if (line_oldpwd == -1)
        create_oldpwd(env);
    line_oldpwd = my_get_line_tab(*env, "OLDPWD=");
    if (line_oldpwd == -1)
        return (-1);
    free((*env)[line_oldpwd]);
    tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    if ((*env)[line_oldpwd] == NULL)
        return (-1);
    tmp = my_strcpy(tmp, "OLDPWD=");
    (*env)[line_oldpwd] = my_strcat(tmp, str);
    free(tmp);
    return (0);
}
