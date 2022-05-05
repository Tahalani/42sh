/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** #FreeKOSOVO
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 31 && str[i] > 126)
            return (0);
    }
    return (1);
}
