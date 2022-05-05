/*
** EPITECH PROJECT, 2021
** my
** File description:
** #FreeKOSOVO
*/

#ifndef MY_H_
    #define MY_H_

    #define ATOD(x) (x - '0')
    #define DTOA(x) (x + '0')

    #include <stdarg.h>

/*- CHAR INFO FUNCTIONS -*/
/*-----------------------*/

int my_char_isnum(char const c);
int my_char_isalpha(char const c);
int my_char_islower(char const c);
int my_char_isupper(char const c);
int my_char_is_alpha_num(char const c);
int my_char_is_printable(char const c);
int my_count_char_in_str(char const *str, char c);
int my_char_is_in_str(char const *, char const c);

/*-          END         -*/
/*------------------------*/
/*-  STR INFO FUNCTIONS  -*/

int my_strlen(char const *);
int my_getnbr(char const *);
int my_showstr(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isalpha(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_strcmp(char const *, char const *);
int my_showmem(char const *str, int size);
int my_strncmp(char const *, char const *, int const n);

/*-        END          -*/
/*----------------------*/
/*-   STR  FUNCTIONS   -*/

char *my_revstr(char *);
char *my_strupcase(char *);
char *my_int_to_str(int nb);
char *my_strlowcase(char *);
char *my_strdup(char const *);
char *my_strcapitalize(char *);
char *my_file_in_str(char const *filepath);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char const *s1, char const *s2);
char *my_get_first_line_file(char const *filepath);
char *my_strtok(char const *str, char const *delim);
char *my_strstr(char const *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int const n);
char *my_strncat(char *dest, char const *src, int const n);

/*-         END        -*/
/*----------------------*/
/*-   FREE  FUNCTIONS  -*/

void my_free_array(char **);
int my_freef(char *s, ...);
void my_free_int_array(int **, int nb_rows);

/*-        END         -*/
/*-----------------------*/
/*-  PRINT  FUNCTIONS  -*/

void my_putchar(char const c);
void my_putstr(char const *);
void my_puterr(char const *);
int my_put_nbr(int const nb);
void my_show_word_array(char **);
void my_putchar_error(char const c);
void my_putnchar(char const c, int const n);
int my_write_in_file(char const *filepath, char const *text);

/*-        END        -*/
/*---------------------*/
/*-MY_PRINT  FUNCTIONS-*/

int my_printf(char *s, ...);
int sum_numbers(int n, ...);
int my_putlong(long int nb);
int my_putchar_special(char c);
int sum_strings_length(int n, ...);
int my_put_special(char const *str);
void put_space(char const *str, int i);
int my_putnbr_base(int nb, char *base);
void my_print_int_array(int **, int nb_col, int nb_ligne);

/*-        END         -*/
/*----------------------*/
/*- 2D ARRAY FUNCTIONS -*/

int my_len_array(char **);
char **my_copy_tab(char **);
char **my_str_to_word_array(char const *);
int my_get_line_tab(char **, char const *);
void my_sort_int_array(int *tab, int const size);
void my_strcat_in_array(char **arr, char const *str);
char **my_file_in_2d_char_array(char const *filepath);
char **my_stwa_separator(char const *, char const *separator);
char **my_malloc_2d_char_array(int const nb_col, int const nb_line);
int **my_malloc_2d_int_array(int const nb_rows, int const nb_cols);
void my_replace_in_tab(char **tab, char const old, char const new_element);

/*-        END         -*/
/*----------------------*/
/*-   INT  FUNCTIONS   -*/

int my_find_prime_sup(int);
int my_isneg(int const nb);
void my_swap(int *a, int *b);
int my_is_prime(int const nb);
int my_compute_square_root(int);
int my_compute_power_rec(int nb, int power);

/*-        END         -*/
/*----------------------*/

#endif/* MY_H_ */
