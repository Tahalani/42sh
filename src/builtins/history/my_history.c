/*
** EPITECH PROJECT, 2022
** my_history
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>

#include "my.h"
#include "builtins.h"

int handle_flags(char **commands, char const *filepath_history)
{
    if (!my_strcmp(commands[1], "-c"))
        my_clean_file(filepath_history);
    else if (my_str_isnum(commands[1]))
        my_print_file_n_last_line(filepath_history, atoi(commands[1]));
    else {
        my_puterr("history: Badly formed number.\n");
        return -1;
    }
    return 0;
}

int my_history(char **commands, shell_t *save)
{
    char const *filepath_history =
        my_strcat(my_get_line_env(save->env, "HOME="), "/.42sh_history");

    if (filepath_history == NULL)
        return -1;
    if (my_len_array(commands) == 1) {
        my_print_file(filepath_history);
        my_freef("%s", filepath_history);
        return 0;
    }
    if (my_len_array(commands) == 2) {
        if (handle_flags(commands, filepath_history) == -1) {
            my_freef("%s", filepath_history);
            return -1;
        }
    }
    my_freef("%s", filepath_history);
    return 0;
}
