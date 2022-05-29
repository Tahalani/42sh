/*
** EPITECH PROJECT, 2022
** pipe
** File description:
** pipe file
*/

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "my.h"
#include "mysh.h"

void execute(char *str, shell_t *save)
{
    char **commands = my_str_to_word_array(str);
    char **bin = my_getenv(save->env, "PATH=");
    char *str2 = my_strcat("/", commands[0]);

    my_strcat_in_array(bin, str2);
    if (bin != NULL) {
        for (int i = 0; bin[i] != NULL; ++i)
            execve(bin[i], commands, save->env);
    }
    execve(commands[0], commands, save->env);
    my_puterr(commands[0]);
    my_puterr(": Command not found.\n");
    my_freef("%t%t%s", commands, bin, str2);
}

static int dup_and_execute(int fildes[2], int sec_fd, char *commands,
    shell_t *save)
{
    int pid = 0;

    pid = fork();
    if (pid == 0) {
        dup2(fildes[sec_fd], sec_fd);
        close(fildes[sec_fd]);
        if (sec_fd == 0)
            close(fildes[1]);
        else
            close(fildes[0]);
        execute(commands, save);
    }
    return pid;
}

void manage_pipe(char *commands, shell_t *save)
{
    char **array = my_stwa_separator(commands, "|");
    int fildes[2];
    int pid[2] = {0};

    if (array == NULL)
        return;
    if (pipe(fildes) == -1)
        return;
    pid[0] = dup_and_execute(fildes, STDOUT_FILENO, array[0], save);
    pid[1] = fork();
    if (pid[1] == 0) {
        dup2(fildes[0], STDIN_FILENO);
        close(fildes[0]);
        close(fildes[1]);
        if (my_len_array(array + 1) > 1)
            manage_pipe(commands + strlen(array[0]), save);
        execute(array[1], save);
    }
    close(fildes[0]);
    close(fildes[1]);
    waitpid(pid[0], NULL, 0);
    waitpid(pid[1], NULL, 0);
}

// void handle_pipe(char *line, char **env[])
// {
//     char **command = my_str_to_word_array(line, "|");
//     int fildes[2];
//     int pid[2];

//     if (command == NULL)
//         return;
//     pipe(fildes);
//     pid[0] = dup_and_execute(fildes, STDOUT_FILENO, env, command[0]);
//     pid[1] = dup_and_execute(fildes, STDIN_FILENO, env, command[1]);
//     close(fildes[0]);
//     close(fildes[1]);
//     waitpid(pid[0], NULL, 0);
//     waitpid(pid[1], NULL, 0);
// }


// void execute_first_command(char *command, int fd[2], shell_t *save)
// {
//     int pid = fork();

//     if (pid == 0) {
//         dup2(fd[1], STDOUT_FILENO);
//         close(fd[0]);
//         execute(command, save);
//     }
// }

// void execute_second_command(char *command, int fd[2], shell_t *save)
// {
//     int pid = fork();

//     if (pid == 0) {
//         dup2(fd[0], STDIN_FILENO);
//         close(fd[1]);
//         execute(command, save);
//     }
// }

// void launch_pipe(char **command, shell_t *save)
// {
//     int fd[2];

//     pipe(fd);
//     execute_first_command(command[0], fd, save);
//     execute_second_command(command[1], fd, save);
//     waitpid(-1, NULL, 0);
// }

// void manage_pipe(char *commands, shell_t *save)
// {
//     char **command = my_stwa_separator(commands, "|\n");
//     if (command[1] == NULL) {
//         my_puterr("Invalid null command.\n");
//         my_freef("%t", command);
//         return;
//     }
//     launch_pipe(command, save);
//     my_freef("%t", command);
// }
