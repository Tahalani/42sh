/*
** EPITECH PROJECT, 2022
** B-PSU-210-PAR-2-1-minishell2-lindon.aliu
** File description:
** tests_unit_setenv
*/

#include "mysh.h"
#include "my.h"
#include <criterion/criterion.h>

int error_setenv(char **commands, char ***env, int *value);
char **my_setenv(char **env, char **commands, int *return_value);

// shell_t save;
// save.env = env;
// save.str = "exit 181214caca";
// manage_separator(&save);

// Test(my_setenv, my_setenv0)
// {
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[1] = NULL;
//     char *commands[] = {"setenv", "zou"};
//     int b = 0;
//     env = my_setenv(env, commands, &b);
//     cr_assert_eq(b, 0);
//     my_free_array(env);
// }

Test(manage_separator, setenv2)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv z0,u zou";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, setenv_error)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv z0(u zou";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, setenv_error2)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv z0)u zou";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, setenv_error3)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv z0()u zou";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, setenv_error4)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv 18z0u zou";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, setenv_error5)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv z0u zou love";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, unsetenv)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "unsetenv zou zou";
    manage_separator(&save);
    save.str = "unsetenv zou";
    manage_separator(&save);
    save.str = "unsetenv";
    manage_separator(&save);
    save.str = "unsetenv PWD";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_separator, unsetenv2)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    env[1] = my_strdup("lindon=zouzoulove");
    env[2] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "unsetenv PWD";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

// Test(manage_separator, setenv_error5)
// {
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[1] = NULL;
//     int a = 0;
//     shell_t save;
//     save.env = env;
//     save.str = "setenv zou--;:";
//     manage_separator(&save);
//     cr_assert_eq(a, 0);
//     my_free_array(env);
// }

// Test(manage_separator, setenv_error)
// {
//     char *commands[] = { "setenv", "z0u", "zou", NULL };
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[1] = NULL;
//     int a = 0;
//     cr_assert_eq(a, 0);
//     my_free_array(env);
// }

// Test(manage_separator, setenv_error4)
// {
//     char *commands[] = { "setenv", "_zu", "zou", NULL };
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[1] = NULL;
//     int a = 0;
//     cr_assert_eq(a, 0);
//     my_free_array(env);
// }

// Test(manage_separator, setenv3)
// {
//     char *commands[] = { "setenv", "PWD", "zouzoulove", NULL };
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[1] = NULL;
//     int a = 0;
//     cr_assert_eq(a, 0);
//     my_free_array(env);
// }
