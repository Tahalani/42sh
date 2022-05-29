/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_printf
*/

#include "../my.h"

void my_printf_4(int *i, va_list list, char *s)
{
    if (s[*i] == '%' && s[*i + 1] == 'x') {
        my_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'p') {
        my_putstr("0x");
        my_putnbr_base(va_arg(list, int), "0123456789abcdef");
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'X') {
        my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
        *i += 2;
    }
}

void my_printf_3(int *i, va_list list, char *s)
{
    if (s[*i] == '%' && s[*i + 1] == 'C') {
        my_putchar_special(va_arg(list, int));
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == '%') {
        my_putchar('%');
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'b') {
        my_putnbr_base(va_arg(list, int), "01");
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'o') {
        my_putnbr_base(va_arg(list, int), "01234567");
        *i += 2;
    }
}

void my_printf_2(int *i, va_list list, char *s)
{
    if (s[*i] == '%' && s[*i + 1] == 's') {
        my_putstr(va_arg(list, char *));
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'S') {
        my_put_special(va_arg(list, char *));
        *i += 2;
    }
    if (s[*i] == '%' && (s[*i + 1] == 'i' || s[*i + 1] == 'd')) {
        my_put_nbr(va_arg(list, int));
        *i += 2;
    }
    if (s[*i] == '%' && s[*i + 1] == 'c') {
        my_putchar(va_arg(list, int));
        *i += 2;
    }
}

void my_printf_5(int *i, va_list list, char *s)
{
    if (s[*i] == '%' && s[*i + 1] == 'l' && s[*i + 2] == 'd') {
        my_putlong(va_arg(list, long int));
        *i += 3;
    }
    if (s[*i] == '%' && s[*i + 1] == 't') {
        my_show_word_array(va_arg(list, char **));
        *i += 2;
    }
}

int my_printf(char *s, ...)
{
    va_list list;
    int a;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        a = i;
        my_printf_2(&i, list, s);
        my_printf_3(&i, list, s);
        my_printf_4(&i, list, s);
        my_printf_5(&i, list, s);
        if (s[i] == '\0')
            return (0);
        if (s[i] == '%' && a != i)
            i--;
        else
            my_putchar(s[i]);
    }
    va_end(list);
    return (0);
}
