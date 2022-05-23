/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** FreeKOSOVO
*/

#ifndef mysh
    #define mysh

    #include <sys/stat.h>
    #include <stddef.h>

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
void handle_backslash(char **commands, int i, size_t *j);
int verif_option_echo(char *commands);
int is_arg_hyphen_n(char *commands);
void echo_opt_maj_e(char **commands);
void echo_opt_e(char **commands);
void print_with_backslash(char **commands, int i);
int verif_solo_quote(char **commands);
void print_simple_case(char *commands);
int error(int const argc, char const *argv[], char const *env[]);

#endif/* !mysh */
