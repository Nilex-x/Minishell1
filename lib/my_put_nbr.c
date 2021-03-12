/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** display nbr
*/

#include "my.h"

int my_put_nbr(long int nb)
{
    int modulo = 0;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 10) {
        modulo = (nb % 10);
        nb = (nb - modulo) / 10;
        my_put_nbr(nb);
        my_putchar(modulo + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (1);
}