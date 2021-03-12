/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates two string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);

    for (int i = 0; i < len_src; i++, len_dest++)
        dest[len_dest] = src[i];
    dest[len_dest] = '\0';
    return (dest);
}