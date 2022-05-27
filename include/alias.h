/*
** EPITECH PROJECT, 2022
** alias_array
** File description:
** FreeKOSOVO
*/

#ifndef ALIAS_H_
    #define ALIAS_H_

    #include "mysh.h"

char **my_malloc_alias_array(char **commands, char **alias);
int my_change_line_in_file(char **file, char **commands, int fd, int i);
int search_alias_already_set(char **commands);
int search_in_tmp_shrc(char **commands, shell_t *save);
int manage_tmp_alias(char **commands);
int cmp_alias_and_cmd(char ***alias, char **commands, shell_t *save);
char *file_to_buffer(const char *file);
char ***parsing_alias(char **file, int i);
int search_in_shrc(char **commands, shell_t *save);
int manage_ftcn(char **commands, shell_t *save);

#endif/* !ALIAS_H_ */
