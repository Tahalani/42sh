/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** #my_is neg
*/

void my_putchar(char const c);

int my_isneg(int const n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}
