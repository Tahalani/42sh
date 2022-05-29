/*
** EPITECH PROJECT, 2022
** search_variables_exist
** File description:
** FreeKOSOVO
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "variables.h"
#include "my.h"

int create_variable(char **commands)
{
    if (my_write_in_file(VARIABLES_TMP_FILE, "var ") == -1)
        return -1;
    if (my_write_in_file(VARIABLES_TMP_FILE, commands[1]) == -1)
        return -1;
    if (my_write_in_file(VARIABLES_TMP_FILE, "=") == -1)
        return -1;
    if (commands[2] == NULL) {
        my_write_in_file(VARIABLES_TMP_FILE, "\n");
        return 0;
    }
    for (int i = 3; commands[i] != NULL && commands[2][0] == '='; i++) {
        if (my_write_in_file(VARIABLES_TMP_FILE, commands[i]) == -1)
            return -1;
        if (commands[i + 1] != NULL)
            my_write_in_file(VARIABLES_TMP_FILE, " ");
    }
    if (my_write_in_file(VARIABLES_TMP_FILE, "\n") == -1)
        return -1;
    return 0;
}

void write_var_in_boucle(char **commands, int fd)
{
    if (commands[2] == NULL || strcmp(commands[2], "=") != 0)
        return;
    for (int i = 3; commands[i] != NULL; i++) {
        write(fd, commands[i], strlen(commands[i]));
        if (commands[i + 1] != NULL)
            write(fd, " ", 1);
    }
}

int my_change_var_line_in_file(char **file, char **commands, int fd, int i)
{
    char *cmd = my_strcat("var ", commands[1]);
    int ret_val = 0;

    if (cmd == NULL)
        return -1;
    if (strncmp(cmd, file[i], 4 + strlen(commands[1])) == 0) {
        write(fd, "var ", strlen("var "));
        write(fd, commands[1], strlen(commands[1]));
        write(fd, "=", 1);
        write_var_in_boucle(commands, fd);
        write(fd, "\n", 1);
        ret_val = 1;
    } else {
        write(fd, file[i], strlen(file[i]));
        write(fd, "\n", 1);
    }
    free(cmd);
    return ret_val;
}

void modif_variable_value(char **file, char **commands, int fd, int *ret_val)
{
    for (int i = 0; file[i] != NULL; i++) {
        if (my_change_var_line_in_file(file, commands, fd, i) == 1)
            *ret_val = 1;
    }
}

int search_variables_already_set(char **commands)
{
    char **file = NULL;
    char *buffer = my_file_in_str(VARIABLES_TMP_FILE);
    int fd = open(VARIABLES_TMP_FILE, O_CREAT | O_RDONLY | O_WRONLY | O_TRUNC,
    0666);
    int ret_val = 0;

    if (buffer == NULL)
        return -1;
    if (fd == -1) {
        free(buffer);
        return -1;
    }
    file = my_stwa_separator(buffer, "\n");
    free(buffer);
    if (file == NULL)
        return -1;
    modif_variable_value(file, commands, fd, &ret_val);
    my_freef("%t", file);
    close(fd);
    return ret_val;
}
