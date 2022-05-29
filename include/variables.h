/*
** EPITECH PROJECT, 2022
** variables
** File description:
** FreeKOSOVO
*/

#ifndef VARIABLES_H_
    #define VARIABLES_H_

    #define VARIABLES_TMP_FILE "/tmp/.variables_42.tmp"
    #include "mysh.h"

void print_var_already_set(char *file);
char ***parsing_var(char **file, int i);
char **my_malloc_var_array(char **commands, char **var);
int search_in_tmp_var_file(char **commands, shell_t *save);
int create_variable(char **commands);
int search_variables_already_set(char **commands);
void my_free_3d_array(char ***array);

#endif/* !VARIABLES_H_ */
