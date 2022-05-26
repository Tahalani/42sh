/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** FreeKOSOVO
*/

#ifndef mysh
    #define mysh

    #include <sys/stat.h>

typedef struct path_s {
    char **env;
    char **commands;
    int status;
    char **bin;
    char *str;
} path_t;

typedef struct shell_s {
    char *str;
    char **env;
    char **all_commands;
    int return_value;
    int status;
} shell_t;

int myshell(shell_t *);
void ctrl_c(int sig);
int check_crash(int status, int *return_value);
int manage_alias(char **commands, shell_t *save);
void copy_file_in_directory(char *file_path, char *dest);
void manage_commands(char **commands, shell_t *);
void manage_separator(shell_t *save);
int manage_builtins(char **commands, shell_t *);
int check_access(char **commands, shell_t *);
int check_path(char **commands, shell_t *);
void error_execve(char *str, char **commands, char **env, int *value);
void check_status(int status, int *value);

void manage_pipe(char *commands, shell_t *);
void launch_pipe(char **command, shell_t *);
void manage_redirection(char const *commands, shell_t *save);
void launch_redirect(char const *command, char const *direction,
    shell_t *save);
void launch_double_redirect(char const *command,
    char const *direction, shell_t *save);

char *my_get_line_env(char **env, char *str);
void put_2_elements(char *str, int *value);
char **my_getenv(char **env, char *str);
char *my_get_line_env(char **env, char *str);
char gettype(struct stat stats);

int error(int const argc, char const *argv[], char const *env[]);

#endif/* !mysh */
