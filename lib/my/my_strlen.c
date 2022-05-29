/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int counter;

    for (counter = 0; str[counter] != '\0'; counter++);
    return (counter);
}
