/*
** EPITECH PROJECT, 2022
** manage_commands
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include <string.h>

#include "commands_array.h"
#include "redirection.h"
#include "my.h"
#include "mysh.h"
#include "if.h"

int analyse_commands(char **commands, shell_t *save)
{
    for (int i = 0; i != 3; i++) {
        if ((*COMMANDS_ARRAY[i])(commands, save) == 0)
            return (0);
    }
    return (-1);
}

void manage_commands(char **commands, shell_t *save)
{
    if (commands == NULL || commands[0] == NULL)
        return;
    if (analyse_commands(commands, save) == -1) {
        my_puterr(commands[0]);
        my_puterr(": Command not found.\n");
        save->return_value = 1;
    }
}

void manage_other_separator(char *commands, shell_t *save)
{
    char **command = NULL;

    if (commands == NULL)
        return;
    if (my_char_is_in_str(commands, '>') == 1 ||
    my_char_is_in_str(commands, '<') == 1)
        manage_redirection(commands, save);
    if (strstr(commands, "if"))
        manage_if(commands, save);
    else if (my_char_is_in_str(commands, '|') == 1) {
        manage_pipe(commands, save);
    } else {
        command = my_str_to_word_array(commands);
        if (command == NULL)
            return;
        manage_commands(command, save);
        my_free_array(command);
    }
}

void manage_separator(shell_t *save)
{
    char const *filepath_history =
        my_strcat(my_get_line_env(save->env, "HOME="), "/.42sh_history");
    my_write_in_file(filepath_history, save->str);
    my_freef("%s", filepath_history);
    if (strstr(save->str, "if") == NULL) {
        save->all_commands = my_stwa_separator(save->str, ";");
    } else
        save->all_commands = my_stwa_separator(save->str, "\n");
    if (save->all_commands == NULL)
        return;
    for (int i = 0; save->all_commands[i] != NULL; i++)
        manage_other_separator(save->all_commands[i], save);
    my_free_array(save->all_commands);
}
