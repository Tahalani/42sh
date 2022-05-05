/*
** EPITECH PROJECT, 2021
** sum_numbers
** File description:
** FreeKOSOVO
*/

#include <stdarg.h>
#include "../my.h"

int sum_numbers(int n, ...)
{
    va_list list;
    int result = 0;

    va_start(list, n);
    for (int i = 0; i < n; i++)
        result += va_arg(list, int);
    va_end(list);
    return (result);
}
