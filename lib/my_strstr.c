/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** ??
*/

#include <stdlib.h>
#include <stdio.h>

int verif_str(char *str, char const *to_find, int n)
{
    int i = 0;
    int c = 0;

    for (; str[n] != '\0' && to_find[i] != '\0'; i++, n++) {
        if (str[n] == to_find[i])
            c++;
    }
    if (i == c)
        return (i);
    else
        return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int verif = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        verif = verif_str(str, to_find, i);
        if (verif != 0)
            return (&str[i]);
    }
    return (0);
}