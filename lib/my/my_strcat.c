/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** #FreeKOSOVOO
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char const *s1, char const *s2)
{
    int len_a = my_strlen(s1);
    int len_b = my_strlen(s2);
    char *result = malloc(sizeof(char) * (len_a + len_b + 1));

    if (result == NULL)
        return NULL;
    for (int i = 0; s1[i] != '\0'; i++)
        result[i] = s1[i];
    for (int i = 0, j = len_a; s2[i] != '\0'; i++, j++)
        result[j] = s2[i];
    result[len_a + len_b] = '\0';
    return (result);
}
