/*
** EPITECH PROJECT, 2020
** my_int_to_str
** File description:
** convert int to str
*/

#include "my.h"

char *my_int_to_str(int nb)
{
    char *str = NULL;
    int modulo = 0;
    int i = 0;

    str = malloc(sizeof(char) * my_intlen(nb) + 1);
    for (; nb > 0; i++) {
        modulo = nb % 10;
        str[i] = modulo + 48;
        nb = (nb - modulo) / 10;
    }
    str[i] = 0;
    return (str);
}