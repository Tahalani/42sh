/*
** EPITECH PROJECT, 2022
** my_history
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include "builtins.h"

int my_history(char **commands, UNUSED shell_t *save)
{
    char const *filepath_history =
        my_strcat(my_get_line_env(save->env, "HOME="), "/.42sh_history");
    if (my_len_array(commands) == 1)
        my_print_file(filepath_history);
    if (my_len_array(commands) == 2 && !my_strcmp(commands[1], "-c"))
        my_clean_file(filepath_history);
    my_freef("%s", filepath_history);
    return 0;
}
