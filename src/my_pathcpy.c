/*
** EPITECH PROJECT, 2020
** my_pathcpy.c
** File description:
** path cpy
*/

#include "my.h"
#include "my_struct.h"

int separate_path(char *str, int i)
{
    int d = 0;
    while (str[i] != ':') {
        if (str[i] == '\0') {
            break;
        }
        i++;
        d++;
    }
    return (d);
}

char *my_pathcpy(int i, env_t *env)
{
    int d = 0;
    char *path = NULL;
    int len_path = separate_path(env->env, i);
    path = malloc(sizeof(char) * len_path + 1);
    while (d < len_path) {
        path[d] = env->env[i];
        i++;
        d++;
    }
    path[d] = '\0';
    return (path);
}