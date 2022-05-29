/*
** EPITECH PROJECT, 2022
** my_get_first_line_file
** File description:
** my_get_first_line file
*/

#include <stdlib.h>

char *my_file_in_str(char const *filepath);
char *my_strncpy(char *dest, char const *src, int n);

char *my_get_first_line_file(char const *filepath)
{
    char *buffer = my_file_in_str(filepath);
    char *result;
    int i = 0;

    for (i = 0; buffer[i] != '\n'; ++i);
    result = malloc(sizeof(char) * (i + 1));
    if (result == NULL) {
        free(buffer);
        return NULL;
    }
    my_strncpy(result, buffer, i);
    result[i] = '\0';
    free(buffer);
    return (result);
}
