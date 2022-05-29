/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int const n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
