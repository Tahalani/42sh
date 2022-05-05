/*
** EPITECH PROJECT, 2022
** my_print_int_array
** File description:
** FreeKOSOVO
*/

int my_printf(char *s, ...);

void my_print_int_array(int const **arr, int nb_col, int nb_ligne)
{
    for (int y = 0; y < nb_ligne; y++) {
        for (int x = 0; x < nb_col; x++)
            my_printf("%d");
        my_printf("\n");
    }
}
