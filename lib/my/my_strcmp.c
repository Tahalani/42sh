/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);
    return (s1[i] - s2[i]);
}
