/*
** EPITECH PROJECT, 2022
** B-PSU-210-PAR-2-1-minishell2-lindon.aliu
** File description:
** test_mysh
*/

#include "mysh.h"
#include <criterion/criterion.h>

// shell_t save;
// save.env = env;
// save.str = "tests/hello";
// manage_separator(&save);

Test(manage_separator, test_env)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "env";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_NULL)
{
    // char **env = malloc(sizeof(char *) * 2);
    // env[0] = "test";
    // env[1] = NULL;
    // int a = 0;
    // shell_t save;
    // save.env = env;
    // save.str = "tests/hello";
    // manage_separator(&save);
    // cr_assert_eq(a, 0);
    // free(env);
}

Test(manage_separator, test_unsetenv)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "unsetenv";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_setenv)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "setenv";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_cd)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "PWD=";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd kkkkk";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_error)
{
    // char *commands[] = { NULL, NULL };
    // char **env = malloc(sizeof(char *) * 2);
    // env[0] = "test";
    // env[1] = NULL;
    // int a = 0;
    // cr_assert_eq(a, 0);
    // free(env);
}

Test(manage_separator, test_command_found)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "clear";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_command_not_found)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "prout";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_exit)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "exit caca";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_exit2)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "exit 10 12";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_exit3)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "exit 181214caca";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_exit4)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "exit";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_exit5)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "exit 18";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_pipe)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "clear | ls";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

// Test(manage_separator, test_redirection)
// {
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = "test";
//     env[1] = NULL;
//     int a = 0;
//     shell_t save;
//     save.env = env;
//     save.str = "clear > ls";
//     manage_separator(&save);
//     cr_assert_eq(a, 0);
//     free(env);
// }

Test(manage_separator, test_redirection2)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "env kk";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(manage_separator, test_cd178965423)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "test";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd prout";
    manage_separator(&save);
    save.str = "cd lib";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}