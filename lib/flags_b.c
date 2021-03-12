/*
** EPITECH PROJECT, 2020
** flags_b
** File description:
** flags b
*/

#include "my.h"

void print_bin(int nb)
{
    if (nb != 0) {
        print_bin(nb / 2);
        if (nb % 2 == 0)
            my_putchar('0');
        else
            my_putchar('1');
    }
}

void flags_b(flags_t *data, ...)
{
    int nb = va_arg(data->list, int);

    print_bin(nb);
    return;
}