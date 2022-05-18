/*
** EPITECH PROJECT, 2022
** tests_error
** File description:
** FreeKOSOVO
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <string.h>
#include "mysh.h"
#include "my.h"

void manage_commands(char **commands, shell_t *save);
void manage_pipe(char *commands, shell_t *save);

Test(error, test_argc)
{
    char const *argv[] = {"", ""};
    char const *env[] = {"", ""};

    cr_assert_eq(error(1, argv, env), 0);
    env[0] = NULL;
    cr_assert_eq(error(1, argv, env), -1);
    cr_assert_eq(error(1, argv, NULL), -1);
    env[0] = "";
    cr_assert_eq(error(20, argv, env), -1);
    ctrl_c(0);
}

Test(my_getenv, test_argv)
{
    char *env[] = {"hello", NULL};
    char *env2[] = {":::", NULL};
    char **hello = my_getenv((char **)env, "he");
    char **wesh = my_getenv(env2, "he");
    my_free_array(hello);
    (void)wesh;
    ctrl_c(10);
}

Test(my_getenv, test_getenv)
{
    char *cmd[] = {NULL, "hello"};
    shell_t save;
    save.str = "pipicaca";
    manage_commands(NULL, &save);
    manage_commands(cmd, &save);
}

Test(my_prompt, test_prompt)
{
    char *env[] = { "USER=HEKO", NULL };
    shell_t save;
    save.str = "pipicaca";
    save.env = env;
    my_prompt(save.env);
    // manage_redirection("cat Makefile > kk", &save);
    // manage_pipe("cat Makefile | kk", &save);
}
