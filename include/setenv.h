/*
** EPITECH PROJECT, 2022
** setenv
** File description:
** FreeKOSOVO
*/

#ifndef SETENV_H_
    #define SETENV_H_

char **my_setenv(char **env, char **commands, int *return_value);
int my_unsetenv(char **env, char **commands);

int error_setenv(char **commands, char ***env, int *value);
int parentheses_2(char **commands, int *check, int i);
int check_second_bracket(int check);

#endif/* !SETENV_H_ */
