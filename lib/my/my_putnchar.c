/*
** EPITECH PROJECT, 2022
** my_putnchar
** File description:
** my_putnchar
*/

void my_putchar(char const c);

void my_putnchar(char const c, int n)
{
    for (int j = n; j > 0; j -= 1)
        my_putchar(c);
}
