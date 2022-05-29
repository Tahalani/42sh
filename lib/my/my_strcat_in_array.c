/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strcat_in_array
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strcat(char const *str1, char const *str2);
char *my_strdup(char const *str);

void my_strcat_in_array(char **arr, char const *str)
{
    char *tmp;
    for (int i = 0; arr[i] != NULL; i++) {
        tmp = my_strdup(arr[i]);
        free(arr[i]);
        arr[i] = my_strcat(tmp, str);
        free(tmp);
    }
}
