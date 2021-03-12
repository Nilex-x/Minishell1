/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi function
*/

int my_atoi(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        result = result * 10;
        result = result + (str[i] - 48);
    }
    return (result);
}