/*
** EPITECH PROJECT, 2022
** B-PSU-210-PAR-2-1-minishell2-lindon.aliu
** File description:
** tests_unit_cd
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include "my.h"
#include "mysh.h"

void manage_separator(shell_t *save);

int builtin_cd(char **commands, char ***env);
int error_cd(char **commands);
int swap_two_elements(char **env);
int load_pwd(char ***env);
int load_oldpwd(char ***env);

Test(manage_commands, error_cd)
{
    char *env[] = { "PATH= TMR LA PUTE: 7SALOPE", NULL };
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd haha";
    manage_separator(&save);
    cr_assert_eq(a, 0);
}

Test(manage_commands, error_cd1)
{
    char *env[] = { "PATH= TMR LA PUTE: 7SALOPE", NULL };
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd mysh";
    manage_separator(&save);
    cr_assert_eq(a, 0);
}

Test(manage_commands, error_cd2)
{
    char *env[] = { "PATH= TMR LA PUTE: 7SALOPE", NULL };
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd mysh cd";
    manage_separator(&save);
    cr_assert_eq(a, 0);
}

Test(manage_separator, error_cd3)
{
    char *env[] = { "PATH= TMR LA PUTE: 7SALOPE", NULL };
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd Makefile";
    manage_separator(&save);
    cr_assert_eq(a, 0);
}

Test(error_cd, error_cd4)
{
    char *commands[] = { "cd", "-", NULL };
    int a = 0;
    error_cd((char **)commands);
    cr_assert_eq(a, 0);
}

Test(error_cd, error_cd5)
{
    char *commands[] = { "cd", "src", NULL };
    error_cd((char **)commands);
    int a = 0;
    cr_assert_eq(a, 0);
}

Test(swap_two_elements, error_cd6)
{
    char **commands = malloc(sizeof(char *) * 3);
    commands[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    commands[1] = my_strdup("OLDPWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu/src");
    commands[2] = NULL;
    int a = swap_two_elements(commands);
    cr_assert_eq(a, 0);
    my_free_array(commands);
}

// Test(swap_two_elements, error_cd7)
// {
//     char **commands = malloc(sizeof(char *) * 3);
//     commands[0] = my_strdup("kaka=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     commands[1] = my_strdup("OLDPWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu/src");
//     commands[2] = NULL;
//     int a = swap_two_elements(commands);
//     cr_assert_eq(a, -1);
//     my_free_array(commands);
// }

Test(load_oldpwd, oldpwd)
{
    char **commands = malloc(sizeof(char *) * 3);
    commands[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    commands[1] = my_strdup("OLDPWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu/src");
    commands[2] = NULL;
    int a = load_oldpwd(&commands);
    cr_assert_eq(a, 0);
    my_free_array(commands);
}

Test(load_oldpwd, create_oldpwd)
{
    char **commands = malloc(sizeof(char *) * 3);
    commands[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    commands[1] = my_strdup("prout=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu/src");
    commands[2] = NULL;
    int a = load_oldpwd(&commands);
    cr_assert_eq(a, 0);
    my_free_array(commands);
}

Test(load_oldpwd, create_oldpwd2)
{
    char **commands = malloc(sizeof(char *) * 2);
    commands[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    commands[2] = NULL;
    int a = load_oldpwd(&commands);
    cr_assert_eq(a, 0);
    my_free_array(commands);
}

Test(load_pwd, create_oldpwd3)
{
    char **commands = malloc(sizeof(char *) * 2);
    commands[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    commands[2] = NULL;
    int a = load_pwd(&commands);
    cr_assert_eq(a, 0);
    my_free_array(commands);
}

Test(load_oldpwd, create_oldpwd4)
{
    char **commands = malloc(sizeof(char *) * 2);
    commands[0] = my_strdup("OLDPWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
    commands[2] = NULL;
    int a = load_oldpwd(&commands);
    cr_assert_eq(a, -1);
    my_free_array(commands);
}

// Test(builtin_cd, error_cd16)
// {
//     char *commands[] = { "cd", "-", NULL };
//     char **env = malloc(sizeof(char *) * 3);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[1] = my_strdup("OLDPDWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu/src");
//     env[2] = NULL;
//     int a = builtin_cd(commands, &env);
//     cr_assert_eq(a, -1);
//     my_free_array(env);
// }

// Test(builtin_cd, error_cd18)
// {
//     char *commands[] = { "cd", "-", NULL };
//     char **env = malloc(sizeof(char *) * 2);
//     env[0] = my_strdup("PWD=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     env[2] = NULL;
//     int a = builtin_cd(commands, &env);
//     cr_assert_eq(a, -1);
//     my_free_array(env);
// }

// Test(swap_two_elements, error_cd66)
// {
//     char **commands = malloc(sizeof(char *) * 3);
//     commands[0] = my_strdup("wesh=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu");
//     commands[1] = my_strdup("alors=/home/laliu/Documents/epitech/tek1/projects/C/minishell/minishell_1/B-PSU-101-PAR-1-1-minishell1-lindon.aliu/src");
//     commands[2] = NULL;
//     int a = swap_two_elements(commands);
//     cr_assert_eq(a, -1);
//     my_free_array(commands);
// }

Test(manage_commands, error_cdd)
{
    char *env[] = { "PATH= TMR LA PUTE: 7SALOPE", NULL };
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "cd kaka";
    manage_separator(&save);
    cr_assert_eq(a, 0);
}

int check_words(char **commands, char ***env);

void free_elements(char **commands, char **env);

Test(check_words, error_cdd)
{
    char *commands[] = { "cd", "PATH=", NULL };
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=hello");
    env[1] = NULL;
    char **kaka = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=hello");
    env[1] = NULL;
    check_words(commands, &env);
    int a = 0;
    free_elements(env, kaka);
    cr_assert_eq(a, 0);
}

int parentheses_2(char **commands, int *check, int i);

Test(check_words, error_partheses)
{
    char *commands[] = { "cd", "lib", NULL };
    char **env = malloc(sizeof(char *) * 4);
    env[0] = my_strdup("PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env[1] = my_strdup("OLDPWD=/home/laliu/Documents/epitech/B2/B2-Shell_Programming/B-PSU-210-PAR-2-1-minishell2-lindon.aliu");
    env[2] = my_strdup("PWD=/home/laliu/Documents/epitech/B2/B2-Shell_Programming/B-PSU-210-PAR-2-1-minishell2-lindon.aliu");
    env[3] = NULL;
    int a = 0;
    builtin_cd(commands, &env);
    char *commands3[] = { "cd", NULL };
    builtin_cd(commands3, &env);
    char *commands2[] = { "cd", "-", NULL };
    builtin_cd(commands2, &env);
    char **env2 = malloc(sizeof(char *) * 4);
    env2[0] = my_strdup("kaka=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env2[1] = my_strdup("pipi=/home/laliu/Documents/epitech/B2/B2-Shell_Programming/B-PSU-210-PAR-2-1-minishell2-lindon.aliu");
    env[2] = NULL;
    char *commands4[] = { "cd", "~", NULL };
    builtin_cd(commands4, &env2);
    load_oldpwd(&env2);
    cr_assert_eq(a, 0);
}
