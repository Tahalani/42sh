/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** if_flag
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

int if_flag_e_a(UNUSED char const *commands,
    char **command_array, UNUSED shell_t *save)
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

int if_flag_d(UNUSED char const *commands,
    char **command_array, UNUSED shell_t *save)
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

int if_flag_r(UNUSED char const *commands,
    char **command_array, UNUSED shell_t *save)
{
    struct stat stats;
    char *buffer;
    int fd = open(command_array[2], O_RDONLY);

    if (stat(command_array[2], &stats) == -1)
        return (-1);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (fd != -1 && read(fd, buffer, stats.st_size) != -1) {
        free(buffer);
        close(fd);
        return (2);
    } else {
        free(buffer);
        return (0);
    }
}
