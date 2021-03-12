/*
** EPITECH PROJECT, 2020
** manage_struct
** File description:
** manage struct
*/

#include "my.h"

void init_data_printf(flags_t *data)
{
    char *o = "scdiufSbpoxX";

    data->o = malloc(sizeof(char) * 13);
    for (int i = 0; i < 13; i++) {
        data->o[i] = o[i];
        data->o[i + 1] = '\0';
    }
    data->flags_n = 0;
    data->len_print = 0;
    data->nb = 0;
    data->p = 0;
    data->s = NULL;
}

void free_all(char **flags, flags_t *data)
{
    if (data->s != NULL)
        free(data->s);
    for (int i = 0; flags[i]; i++)
        free(flags[i]);
    free(flags);
}