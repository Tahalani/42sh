/*
** EPITECH PROJECT, 2022
** Minishell2
** File description:
** cd
*/

#ifndef CD_H_
    #define CD_H_

int builtin_cd(char **commands, char ***env);
int error_cd(char **commands);

int load_oldpwd(char ***env);
int load_pwd(char ***env);

#endif/* !CD_H_ */
