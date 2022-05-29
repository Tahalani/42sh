/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int const nb)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + i] = '\0';
    return (dest);
}
