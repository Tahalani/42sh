/*
** EPITECH PROJECT, 2022
** copy_file_in_directory
** File description:
** FreeKOSOVO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"

static char *my_malloc_char_star(int size)
{
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * size + 1);
    buffer[size] = '\0';
    return buffer;
}

char *file_to_buffer(const char *file)
{
    int fd = 0;
    struct stat sb;
    char *buffer = NULL;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;
    if (stat(file, &sb) == -1) {
        close(fd);
        return NULL;
    }
    buffer = my_malloc_char_star(sb.st_size);
    if (buffer == NULL) {
        close(fd);
        return NULL;
    }
    if (read(fd, buffer, sb.st_size) == -1)
        return NULL;
    close(fd);
    return buffer;
}

void copy_file_in_directory(char *file_path, char *dest)
{
    if (open(dest, O_RDONLY) != -1) {
        free(dest);
        return;
    }
    char *buffer = file_to_buffer(file_path);

    if (buffer == NULL) {
        free(dest);
        return;
    }
    if (my_write_in_file(dest, buffer) == -1) {
        my_freef("%s%s", dest, buffer);
        return;
    }
    my_freef("%s%s", dest, buffer);
    return;
}
