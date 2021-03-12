/*
** EPITECH PROJECT, 2020
** count_char
** File description:
** count char
*/

int count_char_str(char *str, char to_find)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find)
            count++;
    }
    return (count);
}