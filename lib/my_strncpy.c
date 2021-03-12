/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n char of string in other str
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == 0)
        return (dest);
    for (; i <= n; i++) {
        if (src[i] != '\0' || src[i] != 0)
            dest[i] = src[i];
        else
            dest[i] = '\0';
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy_n(char *dest, char const *src , int n)
{
    int i = 0;
    while (i <= n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy_d(char *dest, char const *src, int i)
{
    int d = 0;
    while (src[i] != '\0') {
        dest[d] = src[i];
        i++;
        d++;
    }
    dest[d] = '\0';
    return (dest);
}