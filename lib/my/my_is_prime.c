/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** #my is_prime
*/

int my_is_prime(int const nb)
{
    int i;

    if (nb <= 1) {
        return 0;
    }
    for (i = 2; i < nb - 1; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
