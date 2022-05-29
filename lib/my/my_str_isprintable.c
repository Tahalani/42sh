/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 31 && str[i] > 126)
            return (0);
    }
    return (1);
}
