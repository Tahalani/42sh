/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && str[i] != ' ')
            return (0);
    }
    return (1);
}
