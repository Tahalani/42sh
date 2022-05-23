/*
** EPITECH PROJECT, 2022
** my_history
** File description:
** FreeKOSOVO
*/

#include "my.h"
#include "builtins.h"

void print_file(char const *filepath)
{
    char *str = my_file_in_str(filepath);

    my_printf("%s", str);
    my_freef("%s", str);
}

int my_history(char **commands, UNUSED shell_t *save)
{
    if (my_len_array(commands) == 1) {
        print_file(filepath_history);
        return 0;
    }
    return 0;
}
