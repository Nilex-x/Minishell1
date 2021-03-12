/*
** EPITECH PROJECT, 2020
** my_put_float
** File description:
** display float
*/

#include "my.h"

void my_put_float(double nb)
{
    int len = 0;
    char *str = NULL;

    for (int i = 0; i < 6; i++)
        nb = nb * 10;
    len = my_intlen(nb);
    len = len - 6;
    str = my_int_to_str(nb);
    my_revstr(str);
    for (int i = 0; str[i]; i++) {
        if (i == len)
            my_putchar('.');
        my_putchar(str[i]);
    }
    free(str);
}