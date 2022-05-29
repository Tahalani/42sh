/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (0);
    }
    return (1);
}
