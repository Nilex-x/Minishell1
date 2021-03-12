/*
** EPITECH PROJECT, 2020
** display_env
** File description:
** display var of env
*/

#include "my.h"
#include "my_struct.h"

void display_env(env_t *env, path_t *data)
{
    env = data->head;
    while (env->next != NULL) {
        if (env->name_env != NULL)
            my_putstr(env->name_env);
        if (env->env != NULL)
            my_putstr(env->env);
        my_putchar('\n');
        env = env->next;
    }
    if (env->name_env != NULL)
        my_putstr(env->name_env);
    if (env->env != NULL)
        my_putstr(env->env);
    if (env->env != NULL || env->name_env != NULL)
        my_putchar('\n');
    env = data->head;
}

void free_env_var(char *temp, env_t *env)
{
    my_putstr("zebi");
    while (env->next != NULL) {
        if (my_strcmp(temp, env->name_env) != -1) {
            free(env->env);
            env->env = NULL;
        }
    env = env->next;
    }
}