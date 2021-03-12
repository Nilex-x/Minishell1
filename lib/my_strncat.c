/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** concatenate two string of n char
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; i <= n; i++, len_dest++) {
        if (src[i] != 0)
            dest[len_dest] = src[i];
        else
            dest[len_dest] = '\0';
    }
    dest[len_dest] = '\0';
    return (dest);
}