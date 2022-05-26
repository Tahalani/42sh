/*
** EPITECH PROJECT, 2022
** alias_array
** File description:
** FreeKOSOVO
*/

#ifndef ALIAS_H_
    #define ALIAS_H_

    #include "mysh.h"

int cmp_alias_and_cmd(char ***alias, char **commands, shell_t *save);
char *file_to_buffer(const char *file);
char ***parsing_alias(char **file, int i);
int search_in_shrc(char **commands, shell_t *save);

#endif/* !ALIAS_H_ */
