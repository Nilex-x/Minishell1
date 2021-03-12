/*
** EPITECH PROJECT, 2020
** flags_p
** File description:
** print adress of var
*/

#include "my.h"

void convert_hex_upper(unsigned int nb)
{
    int temp = 0;

    if (nb != 0) {
        convert_hex_upper(nb / 16);
        temp = nb % 16;
        if (temp < 10)
            my_putchar(temp + 48);
        else
            my_putchar(temp + 55);
    }
}

void flags_up_x(flags_t *data, ...)
{
    unsigned int nb = va_arg(data->list, unsigned int);

    convert_hex_upper(nb);
}

void convert_hex_lower(unsigned long int nb)
{
    int temp = 0;

    if (nb != 0) {
        convert_hex_lower(nb / 16);
        temp = nb % 16;
        if (temp < 10)
            my_putchar(temp + 48);
        else
            my_putchar(temp + 87);
    }
}

void flags_x(flags_t *data, ...)
{
    unsigned int nb = va_arg(data->list, unsigned int);

    convert_hex_lower(nb);
}

void flags_p(flags_t *data, ...)
{
    unsigned long int nb = va_arg(data->list, unsigned long int);

    my_putchar('0');
    my_putchar('x');
    convert_hex_lower(nb);
}