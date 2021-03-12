/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** put uppercase on firt char a word
*/

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if ((str[i - 1] < '0' || str[i - 1] > '9')
            && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
    }
    return (str);
}