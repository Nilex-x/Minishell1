/*
** EPITECH PROJECT, 2020
** flags_up_s
** File description:
** flags upper s
*/

#include "my.h"

void print_octal(int c, flags_t *data)
{
    if (c != 0) {
        data->len_print++;
        print_octal(c / 8, data);
        my_putchar((c % 8) + 48);
    }
}

void flags_o(flags_t *data, ...)
{
    int nb = va_arg(data->list, int);

    print_octal(nb, data);
}

void flags_up_s(flags_t *data, ...)
{
    char *s = va_arg(data->list, char *);

    for (int i = 0; s[i]; i++) {
        if (s[i] > 32 && s[i] < 127) {
            my_putchar(s[i]);
            data->len_print++;
        } else {
            my_putchar('\\');
            my_putchar('0');
            if (s[i] > 10) {
                data->len_print++;
                my_putchar('0');
            }
            print_octal(s[i], data);
            data->len_print += 2;
        }
    }
    return;
}