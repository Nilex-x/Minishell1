/*
** EPITECH PROJECT, 2020
** all_flags
** File description:
** print flags
*/

#include "my.h"

void flags_s(flags_t *data, ...)
{
    char *s = va_arg(data->list, char *);

    my_putstr(s);
    data->len_print += my_strlen(s);
}

void flags_c(flags_t *data, ...)
{
    char c = va_arg(data->list, int);

    my_putchar(c);
    data->len_print++;
}

void flags_d(flags_t *data, ...)
{
    long int i = va_arg(data->list, int);

    my_put_nbr(i);
    data->len_print += my_intlen(i);
}

void flags_f(flags_t *data, ...)
{
    double i = va_arg(data->list, double);

    my_put_float(i);
    data->len_print += my_intlen(i) + 6;
}

void flags_u(flags_t *data, ...)
{
    unsigned int nb = va_arg(data->list, unsigned int);

    my_put_nbr(nb);
    data->len_print += my_intlen(nb);
}