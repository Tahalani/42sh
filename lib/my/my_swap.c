/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
