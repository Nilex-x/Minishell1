/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** verify if str contain just lowercase
*/

int my_str_islower(char const *str)
{
    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z' || str[i] == ' ')
            return (0);
    }
    return (1);
}