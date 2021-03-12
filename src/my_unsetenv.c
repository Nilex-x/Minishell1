/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** unsetenv
*/

#include "my.h"
#include "my_struct.h"

env_t *remove_node(env_t *env, path_t *data)
{
    env_t *temp_next = env->next;
    env_t *temp_prev = env->prev;
    temp_next->prev = temp_prev;
    temp_prev->next = temp_next;
    free(env->name_env);
    free(env->env);
    free(env);
    env = temp_next;
    return (temp_next);
}

int my_unsetenv(path_t *data, env_t *env)
{
    char *name_env = NULL;
    int len_arg = my_strlen(data->tab[1]);
    name_env = malloc(sizeof(char) * (len_arg + 2));
    my_strcpy(name_env, data->tab[1]);
    name_env[len_arg] = '=';
    name_env[len_arg + 1] = '\0';
    my_puts(name_env);
    while (env->next != NULL) {
        if (my_strcmp(name_env, env->name_env) != -1)
            env = remove_node(env, data);
        env = env->next;
    }
    return (0);
}