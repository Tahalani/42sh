/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] > 'z' || str[i] < 'a'))
            return (0);
    }
    return (1);
}
