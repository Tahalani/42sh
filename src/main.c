/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void free_struct(shell_t *save)
{
    my_free_array(save->env);
    free(save);
}

shell_t *init_struct(char const *env[])
{
    shell_t *save = malloc(sizeof(shell_t));
    if (save == NULL)
        return NULL;
    save->return_value = 0;
    save->env = my_copy_tab((char **)env);
    if (save->env == NULL)
        return NULL;
    return save;
}

int main(int const argc, char const *argv[], char const *env[])
{
    shell_t *save;
    int return_value = 0;

    if (error(argc, argv, env) == -1)
        return (84);
    save = init_struct(env);
    if (save == NULL || myshell(save) == -1)
        return (84);
    return_value = save->return_value;
    free_struct(save);
    (void)argv;
    return (return_value);
}
