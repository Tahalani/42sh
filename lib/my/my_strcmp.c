/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** #FreeKOSOVO
*/

int my_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);
    return (s1[i] - s2[i]);
}
