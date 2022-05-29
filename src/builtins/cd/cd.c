/*
** EPITECH PROJECT, 2022
** cd
** File description:
** cd file
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"
#include "cd.h"

static void free_elements(char *str, char *str2, char *str3, char *str4)
{
    free(str);
    free(str2);
    free(str3);
    free(str4);
}

int swap_two_elements(char **env)
{
    int line_pwd = my_get_line_tab(env, "PWD=");
    int line_oldpwd = my_get_line_tab(env, "OLDPWD=");
    char *str = my_strdup(my_get_line_env(env, "PWD="));
    char *str2 = my_strdup(my_get_line_env(env, "OLDPWD="));
    char *tmp1 = my_strdup("OLDPWD=");
    char *tmp2 = my_strdup("PWD=");

    if (line_pwd == -1 || line_oldpwd == -1 || str == NULL || str2 == NULL
    || tmp1 == NULL || tmp2 == NULL)
        return (-1);
    free(env[line_pwd]);
    free(env[line_oldpwd]);
    env[line_pwd] = my_strcat(tmp2, str2);
    env[line_oldpwd] = my_strcat(tmp1, str);
    if (env[line_pwd] == NULL || env[line_pwd] == NULL)
        return (-1);
    free_elements(str, str2, tmp1, tmp2);
    return (0);
}

void change_directory(char const *filepath, char ***env)
{
    chdir(filepath);
    load_pwd(env);
}

void print_cd_minus(char ***env)
{
    my_printf("%s\n", my_get_line_env(*env, "PWD="));
    change_directory(my_get_line_env(*env, "PWD="), env);
}

int builtin_cd(char **commands, char ***env)
{
    int len_cmd = my_len_array(commands);
    if (error_cd(commands) == -1)
        return (-1);
    if ((len_cmd == 1) || (len_cmd == 2 && my_strcmp(commands[1], "~") == 0)) {
        if (load_oldpwd(env) == -1)
            return (0);
        change_directory(my_get_line_env(*env, "HOME="), env);
        return (0);
    } if (my_len_array(commands) == 2 && my_strcmp(commands[1], "-") == 0) {
        if (swap_two_elements(*env) == -1) {
            my_puterr(": No such file or directory.\n");
            return (-1);
        }
        print_cd_minus(env);
        return (0);
    }
    if (load_oldpwd(env) == 0)
        change_directory(commands[1], env);
    return (0);
}
