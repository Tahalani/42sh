/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** if
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

#include "my.h"
#include "mysh.h"
#include "if.h"
#include "if_array.h"

int if_flag_e_a(char const *commands, char **command_array, shell_t *save)
{
    int fd = open(command_array[2], O_RDONLY);

    (void)commands;
    (void)save;
    if (fd == -1)
        return (-1);
    else {
        close(fd);
        return (2);
    }
}

int if_flag_d(char const *commands, char **command_array, shell_t *save)
{
    DIR *dir = opendir(command_array[2]);

    (void)commands;
    (void)save;
    if (dir != NULL) {
        closedir(dir);
        return (2);
    } else
        return (0);
}

int launch_if_getline(shell_t *save, char **command_after_comma)
{
    size_t size;

    free(save->str);
    save->str = NULL;
    my_putstr("if? ");
    while (getline(&save->str, &size, stdin) > 0) {
        save->str[strlen(save->str) - 1] = '\0';
        if (strcmp(save->str, "endif") == 0)
            break;
        my_putstr("if? ");
    }
    manage_commands(command_after_comma, save);
    return (0);
}

int error_handling_array(char const *commands, char ***command_comma,
    char ***command_after_comma, char ***command_array)
{
    if (*command_comma == NULL)
        return (-1);
    if ((*command_comma)[1] == NULL) {
        my_free_array(*command_comma);
        return (-1);
    }
    *command_after_comma = my_stwa_separator((*command_comma)[1], " \n");
    if (*command_after_comma == NULL)
        return (-1);
    *command_array = my_stwa_separator(commands, "() \n");
    if (*command_array == NULL) {
        my_freef("%t%t", *command_comma, *command_after_comma);
        return (-1);
    }
    return (0);
}

int manage_if(char const *commands, shell_t *save)
{
    char **command_after_comma = NULL;
    char **command_array = NULL;
    int return_value = 0;
    char **command_comma = my_stwa_separator(commands, ";\n");

    if (error_handling_array(commands, &command_comma,
        &command_after_comma, &command_array) == -1)
        return (-1);
    for (int count = 0; count != 3; count++) {
        if (strcmp(command_array[1], OPT_ARRAY[count]) == 0) {
            return_value = (*OPT_FUNC[count])(commands, command_array, save);
            break;
        }
    } if (return_value == 2) {
        manage_commands(command_after_comma, save);
    } else
        launch_if_getline(save, command_after_comma);
    my_freef("%t%t%t", command_comma, command_after_comma, command_array);
    return (return_value);
}
