/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reverse string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int a = my_strlen(str) - 1;
    int b = 0;
    char temp = 0;

    while (b < a) {
        temp = str[b];
        str[b] = str[a];
        str[a] = temp;
        b++;
        a--;
    }
    return (str);
}