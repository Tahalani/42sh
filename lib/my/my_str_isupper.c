/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_str_isupper
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && str[i] != ' ')
            return (0);
    }
    return (1);
}
