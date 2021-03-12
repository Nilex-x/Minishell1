/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** verify if str contain just uppercase
*/

int my_str_isupper(char const *str)
{
    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z' || str[i] == ' ')
            return (0);
    }
    return (1);
}