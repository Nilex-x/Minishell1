/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** verify if str contain just digits
*/

int my_str_isnum(char const *str)
{
    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}