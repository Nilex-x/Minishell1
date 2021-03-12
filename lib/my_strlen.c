/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count char in string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int total = 0;

    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        total++;
    return (total);
}

int my_strlen_n(char const *str, int i)
{
    int d = 0;
    while (str[i] != '\0') {
        i++;
        d++;
    }
    return (d);
}

int my_strlen_path(char *str, int i)
{
    int d = 0;
    while (str[i] != ':' || str[i] != '\0') {
        d++;
        i++;
    }
    return (d);
}

int my_strlen_x(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        i++;
    }
    return (i);
}