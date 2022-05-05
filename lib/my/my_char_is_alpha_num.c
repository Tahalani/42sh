/*
** EPITECH PROJECT, 2022
** my_char_is_alpha_num
** File description:
** FreeKOSOVO
*/

int my_char_isnum(char const c);
int my_char_isalpha(char const c);

int my_char_is_alpha_num(char const c)
{
    return (my_char_isalpha(c) == 1 || my_char_isnum(c) == 1);
}
