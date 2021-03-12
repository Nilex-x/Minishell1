/*
** EPITECH PROJECT, 2020
** find_str
** File description:
** find c string
*/

int count_char_in_str(char c, char *to_find)
{
    int i = 0;
    int verif = 0;

    for (; to_find[i] != '\0'; i++) {
        if (to_find[i] == c)
            verif = 1;
    }
    if (verif == 1)
        return (0);
    else
        return (1);
}