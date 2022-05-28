// /*
// ** EPITECH PROJECT, 2022
// ** manage_alias
// ** File description:
// ** FreeKOSOVO
// */

// #include <string.h>

// #include "alias.h"

// int check_variables(char **commands, shell_t *save)
// {
//     int cpt = 0;

//     for (; commands[cpt]; cpt++);
//     if (cpt == 2)
//         return 0;
//     if (cpt == 1) {
//         printf("SET AFFICHER LE SET\n");
//         return 0;
//     }
// }

// int manage_variables(char **commands, shell_t *save)
// {
//     int ret_val = -1;

//     if (strcmp(commands[0], "set") == 0) {
//         ret_val = check_variables(commands, save);
//         if (ret_val == 0)
//             save->return_value = ret_val;
//         return ret_val;
//     }
//     return ret_val;
// }
