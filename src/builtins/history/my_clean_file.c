/*
** EPITECH PROJECT, 2022
** my_clean_file
** File description:
** deletes everything in a file
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_clean_file(char const *filepath)
{
    int fd = -1;

    remove(filepath);
    fd = open(filepath, O_CREAT, 0666);
    if (fd == -1)
        return;
    close(fd);
}
