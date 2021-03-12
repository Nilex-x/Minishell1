/*
** EPITECH PROJECT, 2020
** my_intlen
** File description:
** count int len
*/

int my_intlen(int nb)
{
    int count = 0;

    while (nb > 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

int my_intlonglen(unsigned long int nb)
{
    int count = 0;

    while (nb > 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}