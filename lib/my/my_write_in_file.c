/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_write_in_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int my_strlen(char const *str);

int my_write_in_file(char const *filepath, char const *text)
{
    int fd = open(filepath, O_CREAT | O_WRONLY | O_APPEND, 0666);

    if (fd == -1)
        return (-1);
    write(fd, text, my_strlen(text));
    close(fd);
    return (0);
}
