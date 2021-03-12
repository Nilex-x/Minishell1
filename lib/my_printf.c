/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "my.h"

int pointer_function(char *flags, flags_t *data)
{
    void (*operator[13])(flags_t *, ...) = \
    {flags_s, flags_c, flags_d, flags_d, flags_u, \
    flags_f, flags_up_s, flags_b, flags_p, flags_o, \
    flags_x, flags_up_x, 0};

    for (int i = 0; data->o[i]; i++) {
        if (data->o[i] - flags[1] == 0) {
            operator[i](data);
            return (1);
        }
    }
    if (flags[0] == '%') {
        my_putchar('%');
        return (1);
    }
    return (0);
}

int flags_hidden(char *flags, flags_t *data)
{
    if (count_char_str(flags, '%') < 1)
        return (0);

    for (int i = 0; flags[i]; i++) {
        if (flags[i] == '%') {
            separate_flags(flags[i + 1], data);
            i++;
        } else
            my_putchar(flags[i]);
    }
    return (1);
}

int verif_flags(char *flags)
{
    int verif = 0;

    for (int i = 0; flags[i]; i++) {
        if (flags[i] != '%')
            verif++;
    }
    return (verif);
}

void sort_flags(char *flags, flags_t *data)
{
    int len_flags = my_strlen(flags);

    if (flags[0] == '\0')
        return;
    if (option_special(flags, data) == 1)
        return;
    if (flags_hidden(flags, data) == 1)
        return;
    if (my_strcmp("%%", flags) != -1) {
        my_putchar('%');
        return;
    }
    if (len_flags != 0)
        data->len_print += len_flags;
    my_putstr(flags);
}

int my_printf(char *str, ...)
{
    flags_t data;
    char **flags = NULL;

    init_data_printf(&data);
    if (str[0] == '\0')
        return (84);
    va_start(data.list, str);
    flags = my_str_to_word_array(str);
    for (int i = 0; flags[i] != NULL; i++) {
        sort_flags(flags[i], &data);
        if (flags[i + 1]) {
            data.len_print++;
            my_putchar(' ');
        }
    }
    find_last_char(str, my_strlen(str) - 1);
    va_end(data.list);
    return (data.len_print);
}