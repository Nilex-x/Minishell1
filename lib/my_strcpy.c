/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** copy str in other str
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == 0)
        return (dest);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}