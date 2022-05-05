/*
** EPITECH PROJECT, 2022
** check_crash
** File description:
** FreeKOSOVO
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

void check_crash(int status, int *return_value)
{
    int signal = WTERMSIG(status);
    *return_value = signal;

    if (signal == SIGSEGV) {
        *return_value = status;
        if (__WCOREDUMP(status))
            my_puterr("Segmentation fault (core dumped)\n");
        else
            my_puterr("Segmentation fault\n");
    }
    if (signal == SIGFPE) {
        *return_value = status;
        if (__WCOREDUMP(status))
            my_puterr("Floating exception (core dumped)\n");
        else
            my_puterr("Floating exception\n");
    }
}

void no_crash(int status, int *return_value)
{
    *return_value = WEXITSTATUS(status);
}

void check_status(int status, int *return_value)
{
    if (WIFSIGNALED(status))
        check_crash(status, return_value);
    if (WIFEXITED(status))
        no_crash(status, return_value);
}
