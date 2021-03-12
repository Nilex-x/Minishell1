/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** get nbr in string
*/

int verify_len_nb_n(char *str)
{
    int boel = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '9' && str[i] > '0') {
            boel = 1;
            count++;
        } else if (boel == 1)
            break;
    }
    if (count >= 10)
        return (1);
    else
        return (0);
}

int verify_sign(char *str, int i, int sign)
{
    if (str[i - 1] > '9' || str[i - 1] < '0') {
        if ((str[i - 1] == '-' && str[i - 2] == '(') || str[i - 2] == '-')
            return (1);
        else if ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
                || (str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
            return (-1);
    }
    return (sign);
}

int my_getnbr_n(char *str, int n)
{
    int boel = 0;
    int sign = 0;
    int nb = 0;

    for (; str[n] != '\0'; n++) {
        if (str[n] <= '9' && str[n] >= '0') {
            sign = verify_sign(str, n, sign);
            boel = 1;
            nb = nb * 10;
            nb = nb + (str[n] - 48);
        } else if (boel == 1)
            break;
    }
    if (sign == 1)
        return (-nb);
    if (sign == -1)
        return (0);
    return (nb);
}