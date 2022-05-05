/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** #FreeKOSOVO
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && str[i] != ' ')
            return (0);
    }
    return (1);
}
