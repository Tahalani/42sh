/*
** EPITECH PROJECT, 2022
** my_count_char_in_str
** File description:
** FreeKOSOVO
*/

int my_count_char_in_str(char const *str, char c)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        i += str[i] == c ? 1 : 0;
    return i;
}
