/*
** EPITECH PROJECT, 2020
** verif_str
** File description:
** verif string arg
*/

#include "my.h"

int verif_str(char *str, flags_t *data)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            if (count_char_in_str(str[i + 1], data->o) == 1)
                return (1);
        }
    }
    return (0);
}

void find_last_char(char *str, int len)
{
    if (str[len] == ' ' || str[len] == '\n')
        my_putchar(str[len]);
}