/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** #FreeKOSOVO
*/

int my_strncmp(char const *s1, char const *s2, int const n)
{
    int diff = *s1 - *s2;

    if (n == 0)
        return (0);
    if (diff == 0) {
        if (*s1 == '\0')
            return (0);
        else
            return my_strncmp(s1 + 1, s2 + 1, n - 1);
    }
    return (diff);
}
