/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** copy and malloc string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len_src = my_strlen(src);
    char *dest = malloc(sizeof(char) * len_src + 1);

    for (int i = 0; i < len_src; i++)
        dest[i] = src[i];
    dest[len_src] = '\0';
    return (dest);
}