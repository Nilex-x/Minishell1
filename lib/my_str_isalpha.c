/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** verify if your str contain just alpha
*/

int my_str_isalpha(char const *str)
{
    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (((str[i] < 'A' || str[i] > 'Z' ) && (str[i] < 'a'
        || str[i] > 'z')) || (str[i] == ' '))
            return (0);
    }
    return (1);
}