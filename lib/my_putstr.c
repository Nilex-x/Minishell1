/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display string
*/

#include "my.h"

int my_putstr(char *str)
{
    if (str == 0)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

int my_putstr_n(char *str , int i)
{
    if (str == 0)
        return (1);
    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}