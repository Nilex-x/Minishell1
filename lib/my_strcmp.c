/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compares two string
*/

#include "my.h"

int my_strcmp(char *src1, char *src2)
{
    int i = 0;
    int verif = 0;
    int len_1 = my_strlen(src1);
    int len_2 = my_strlen(src2);

    if (len_1 != len_2) return (-1);
    while (src1[i] != '\0') {
        if (src1[i] == src2[i]) {
            verif++;
        }
        i++;
    }
    if (verif == len_1) return (0);
    return (-1);
}