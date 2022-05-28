/*
** EPITECH PROJECT, 2022
** search_variables
** File description:
** FreeKOSOVO
*/

#include <string.h>
#include <stdlib.h>

#include "variables.h"
#include "my.h"

void my_free_3d_array(char ***array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_freef("%t", array[i]);
    }
    free(array);
}

int exec_var(char **commands, shell_t *save, char **alias)
{
    char **new_commands = my_malloc_var_array(commands, alias);

    if (new_commands == NULL)
        return -1;
    manage_commands(new_commands, save);
    my_freef("%t", new_commands);
    return 0;
}

int cmp_var_and_cmd(char ***alias, char **commands, shell_t *save)
{
    for (int i = 0; alias[i] != NULL; i++) {
        if (strcmp(commands[0], alias[i][1]) == 0) {
            exec_var(commands, save, alias[i]);
            return 0;
        }
    }
    return (-1);
}

int var_part(char **file, int i, char **commands, shell_t *save)
{
    char ***var;
    int ret_val = 0;

    var = parsing_var(file, i);
    if (var == NULL)
        return -1;
    ret_val = cmp_var_and_cmd(var, commands, save);
    my_free_3d_array(var);
    return ret_val;
}

static int parsing_tmp_var_file(char *buffer, char **commands, shell_t *save)
{
    char **file;

    if (strstr(buffer, commands[0]) == NULL || strstr(buffer, "var") == NULL)
        return -1;
    file = my_stwa_separator(buffer, "\n");
    if (file == NULL)
        return -1;
    for (int i = 0; file[i] != NULL; i++) {
        if (strncmp(file[i], "var", 3) == 0) {
            return (var_part(file, i, commands, save));
        }
    }
    my_freef("%t", file);
    return 0;
}

int search_in_tmp_var_file(char **commands, shell_t *save)
{
    char *buffer;

    buffer = my_file_in_str(VARIABLES_TMP_FILE);
    if (buffer == NULL) {
        my_puterr(commands[0]);
        my_puterr(": Undefined variable.\n");
        return 1;
    }
    if (parsing_tmp_var_file(buffer, commands, save) == -1) {
        my_freef("%s", buffer);
        my_puterr(commands[0]);
        my_puterr(": Undefined variable.\n");
        return 1;
    }
    return my_freef("%s", buffer);
}
