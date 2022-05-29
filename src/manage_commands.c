/*
** EPITECH PROJECT, 2022
** manage_commands
** File description:
** commands management
*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "commands_array.h"
#include "redirection.h"
#include "my.h"
#include "mysh.h"
#include "if.h"

int analyse_commands(char **commands, shell_t *save)
{
    for (int i = 0; i != NBR_CMD; i++) {
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

void manage_logic(char *commands, shell_t *save)
{
    char **command = NULL;
    if (strstr(commands, "||") != NULL) {
        save->return_value = 1;
        command = my_stwa_separator(commands, "|\n");
        for (int i = 0; command[i] != NULL && save->return_value != 0; i++)
            manage_commands(my_str_to_word_array(command[i]), save);
        return;  
    }
    if (strstr(commands, "&&") != NULL) {
        save->return_value = 0;
        command = my_stwa_separator(commands, "&\n");
        for (int i = 0; command[i] != NULL && save->return_value == 0; i++)
            manage_commands(my_str_to_word_array(command[i]), save);
        return;  
    }
}

void manage_other_separator(char *commands, shell_t *save)
{
    char **command = NULL;

    if (commands == NULL)
        return;
    if (strstr(commands, "||") != NULL || strstr(commands, "&&") != NULL) {
        manage_logic(commands, save);
        return;
    }
    if (my_char_is_in_str(commands, '>') == 1 ||
    my_char_is_in_str(commands, '<') == 1)
        manage_redirection(commands, save);
    else if (strstr(commands, "if") != NULL) {
        manage_if(commands, save);
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
    char const *filepath_history =
        my_strcat(my_get_line_env(save->env, "HOME="), "/.42sh_history");
    my_write_in_file(filepath_history, save->str);
    my_freef("%s", filepath_history);
    if (strstr(save->str, "if") == NULL) {
        save->all_commands = my_stwa_separator(save->str, ";");
        if (strncmp(save->all_commands[0], "ls", 2) == 0) {
            save->all_commands[0] = realloc(save->all_commands[0], sizeof(char)
            * (strlen(save->all_commands[0]) + strlen(" --color=auto") + 1));
            save->all_commands[0] =
            strcat(save->all_commands[0], " --color=auto");
        }
    } else
        save->all_commands = my_stwa_separator(save->str, "\n");
    if (save->all_commands == NULL)
        return;
    for (int i = 0; save->all_commands[i] != NULL; i++)
        manage_other_separator(save->all_commands[i], save);
    my_free_array(save->all_commands);
}
