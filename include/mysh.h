/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** FreeKOSOVO
*/

#ifndef mysh
    #define mysh
    #include <sys/stat.h>
    #define UNUSED __attribute__((unused))
    #define INPUT 0

typedef struct path_s {
    char **env;
    char **commands;
    int status;
    char **bin;
    char *str;
} path_t;

typedef struct shell_s {
    char *str;
    char **all_commands;
    char **env;
    int return_value;
    int status;
} shell_t;

int myshell(shell_t *);
void ctrl_c(UNUSED int signal);
int check_crash(int status, int *return_value);
void manage_commands(char **commands, shell_t *);
void manage_separator(shell_t *save);
int manage_builtins(char **commands, shell_t *);
int check_access(char **commands, shell_t *);
int check_path(char **commands, shell_t *);
void error_execve(char *str, char **commands, char **env, int *value);
void check_status(int status, int *value);

char *my_clean_str(char const *str);
void manage_pipe(char *commands, shell_t *);
void launch_pipe(char **command, shell_t *);

void my_prompt(char **);
char *my_get_line_env(char **env, char *str);
void put_2_elements(char *str, int *value);
char **my_getenv(char **env, char *str);
char *my_get_line_env(char **env, char *str);
char gettype(struct stat stats);
int len_array_1d(char const *arr);

int error(int const argc, char const *argv[], char const *env[]);

#endif/* !mysh */
