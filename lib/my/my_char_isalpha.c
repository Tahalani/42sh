/*
** EPITECH PROJECT, 2021
** my_char_isalpha
** File description:
** #my_char_is alpha
*/

int my_char_isalpha(char const c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
