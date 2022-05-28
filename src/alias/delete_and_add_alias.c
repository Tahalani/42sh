/*
** EPITECH PROJECT, 2022
** manage_tmp_alias
** File description:
** FreeKOSOVO
*/

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "alias.h"
#include "my.h"

void write_arg_in_boucle(char **commands, int fd)
{
    for (int i = 2; commands[i] != NULL; i++) {
        write(fd, commands[i], strlen(commands[i]));
        if (commands[i + 1] != NULL)
            write(fd, " ", 1);
    }
}

int my_change_line_in_file(char **file, char **commands, int fd, int i)
{
    char *cmd = my_strcat("alias ", commands[1]);
    int ret_val = 0;

    if (cmd == NULL)
        return -1;
    if (strcmp(cmd, file[i]) == 0) {
        write(fd, "alias ", strlen("alias "));
        write(fd, commands[1], strlen(commands[1]));
        write(fd, "=", 1);
        write_arg_in_boucle(commands, fd);
        write(fd, "\n", 1);
        ret_val = 1;
    } else {
        write(fd, file[i], strlen(file[i]));
        write(fd, "\n", 1);
    }
    free(cmd);
    return ret_val;
}

int my_delete_line_in_file(char **file, char **commands, int fd, int i)
{
    char *cmd = my_strcat("alias ", commands[1]);
    int ret_val = 0;

    if (cmd == NULL)
        return -1;
    if (strncmp(cmd, file[i], 6 + strlen(commands[1])) == 0);
    else {
        write(fd, file[i], strlen(file[i]));
        write(fd, "\n", 1);
    }
    free(cmd);
    return ret_val;
}

int delete_alias(char **commands)
{
    char **file = NULL;
    char *buffer = file_to_buffer(ALIAS_TMP_FILE);
    int fd = open(ALIAS_TMP_FILE, O_CREAT | O_RDONLY | O_WRONLY | O_TRUNC,
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
    for (int i = 0; file[i] != NULL; i++)
        ret_val = my_change_line_in_file(file, commands, fd, i);
    my_freef("%t", file);
    return ret_val;
}

int verif_unalias_arg(char **commands)
{
    int cpt_arg = 0;

    for (; commands[cpt_arg] != NULL; cpt_arg++);
    if (cpt_arg <= 1) {
        my_putstr("unalias: Too few arguments\n");
        return 1;
    }
    if (cpt_arg > 2) {
        my_putstr("unalias: Too much arguments\n");
        return 1;
    }
    return delete_alias(commands);
}
