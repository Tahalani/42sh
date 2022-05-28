/*
** EPITECH PROJECT, 2022
** manage_alias
** File description:
** FreeKOSOVO
*/

#include <string.h>
#include <stdio.h>

#include "variables.h"
#include "mysh.h"
#include "my.h"

int search_in_var_case(char **commands)
{
    commands[1]++;
    if (search_variables_already_set(commands) != 1) {
        my_puterr(commands[1]);
        my_puterr(": Undefined variable.\n");
        commands[1]--;
        return 1;
    }
    commands[1]--;
    return 0;
}

int check_variables(char **commands)
{
    int cpt = 0;

    for (; commands[cpt]; cpt++);
    if (cpt == 1 && commands[0][0] != '$') {
        print_var_already_set(VARIABLES_TMP_FILE);
        return 0;
    }
    if (cpt > 4) {
        my_putstr("set: Variable name must begin with a letter.\n");
        return 1;
    }
    if (commands[1][0] == '$')
        return (search_in_var_case(commands));
    return ((search_variables_already_set(commands) == 1) ? 0 :
    create_variable(commands));
}

int manage_variables(char **commands, shell_t *save)
{
    int ret_val = -1;

    if (strcmp(commands[0], "set") == 0) {
        ret_val = check_variables(commands);
        if (ret_val == 0 || ret_val == 1)
            save->return_value = ret_val;
        return 0;
    }
    if (commands[0][0] == '$') {
        commands[0]++;
        save->return_value = search_in_tmp_var_file(commands, save);
        commands[0]--;
        return 0;
    }
    return ret_val;
}
