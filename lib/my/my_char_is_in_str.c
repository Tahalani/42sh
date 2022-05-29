/*
** EPITECH PROJECT, 2022
** my_char_is_in_str
** File description:
** my_char_is_in
*/

int my_char_is_in_str(char const *str, char const c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}
