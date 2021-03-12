/*
** EPITECH PROJECT, 2020
** option_special
** File description:
** special option
*/

#include "my.h"

void separate_flags(char flags_letter, flags_t *data)
{
    char *flags_full = NULL;

    flags_full = malloc(sizeof(char) * 3);
    flags_full[0] = '%';
    flags_full[1] = flags_letter;
    flags_full[2] = '\0';
    pointer_function(flags_full, data);
    free(flags_full);
}

void find_flags(char *flags, flags_t *data)
{
    int d = 1;

    for (int i = 0; flags[i] != '\0'; i++) {
        if (flags[i] != '%') {
            my_putchar(flags[i]);
        } else {
            separate_flags(flags [i + 1], data);
            i++;
            d++;
        }
    }
}

int option_special(char *flags, flags_t *data)
{
    int flags_nb = 0;

    for (int d = 0; flags[d] != '\0'; d++) {
        if (flags[d] == '%')
            flags_nb++;
    }
    if (flags_nb > 2)
        find_flags(flags, data);
    else
        return (0);
    return (1);
}