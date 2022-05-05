/*
** EPITECH PROJECT, 2021
** cpool day04 task03
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int counter;

    for (counter = 0; str[counter] != '\0'; counter++);
    return (counter);
}
