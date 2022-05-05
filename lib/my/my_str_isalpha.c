/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** #FreeKOSOVO
*/

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] > 'z' || str[i] < 'a'))
            return (0);
    }
    return (1);
}
