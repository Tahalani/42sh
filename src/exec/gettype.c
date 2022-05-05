/*
** EPITECH PROJECT, 2022
** gettype
** File description:
** FreeKOSOVO
*/

#include <sys/stat.h>

char gettype(struct stat stats)
{
    return ((S_ISDIR(stats.st_mode) ? 'd' :
    (S_ISREG(stats.st_mode) ? 'f' : ' ')));
}
