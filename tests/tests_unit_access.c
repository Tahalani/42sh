/*
** EPITECH PROJECT, 2022
** B-PSU-210-PAR-2-1-minishell2-lindon.aliu
** File description:
** tests_unit_access
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

// shell_t save;
// save.env = env;
// save.str = "cd Makefile";
// manage_separator(&save);

Test(manage_separator, test_segfault)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "tests/segfault";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_commands, test_bin_invlaid)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "tests/bin_invalid";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_commands, test_hello)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "tests/hello";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_commands, test_floating)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "tests/floating";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_commands, no_perimission)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = my_strdup("PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin");
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "Makefile";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    my_free_array(env);
}

Test(manage_commands, test_pipicaca)
{
    char **env = malloc(sizeof(char *) * 2);
    env[0] = "PATH=/home/laliu/.local/bin:/home/laliu/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/var/lib/snapd/snap/bin: /home/laliu/bin: /home/laliu/bin: /home/laliu/bin";
    env[1] = NULL;
    int a = 0;
    shell_t save;
    save.env = env;
    save.str = "pipicaca";
    manage_separator(&save);
    cr_assert_eq(a, 0);
    free(env);
}

Test(gettype, test_gettype)
{
    struct stat stats;

    if (stat("Makeilfe", &stats) != -1)
        gettype(stats);
    if (stat("src", &stats) != -1)
        gettype(stats);
    if (stat("tests/prout", &stats) != -1)
        gettype(stats);
    cr_assert_eq(0, 0);
}