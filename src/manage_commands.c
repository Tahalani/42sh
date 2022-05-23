/*
** EPITECH PROJECT, 2022
** manage_commands
** File description:
** FreeKOSOVO
*/

#include <stddef.h>
#include "my.h"
#include "commands_array.h"
#include "mysh.h"

int analyse_commands(char **commands, shell_t *save)
{
    for (int i = 0; i != 3; i++) {
        if ((*COMMANDS_ARRAY[i]) (commands, save) == 0)
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
    my_char_is_in_str(commands, '<') == 1) {
        manage_redirection(commands, save);
    } else if (my_char_is_in_str(commands, '|') == 1) {
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
    save->all_commands = my_stwa_separator(save->str, ";");
    if (save->all_commands == NULL)
        return;
    for (int i = 0; save->all_commands[i] != NULL; i++)
        manage_other_separator(save->all_commands[i], save);
    my_free_array(save->all_commands);
}
