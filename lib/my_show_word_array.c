/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** show word in array
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++)
        my_puts(tab[i]);
    return (0);
}