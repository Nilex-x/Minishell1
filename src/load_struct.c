/*
** EPITECH PROJECT, 2020
** load_struc
** File description:
** load linked list
*/

#include "my.h"
#include "my_struct.h"

int load_env(env_t *env, char *envp)
{
    int i = 0;
    while (envp[i] != '=')
        i++;
    env->name_env = malloc(sizeof(char ) * i + 2);
    env->env = malloc(sizeof(char) * my_strlen(envp) + 1);
    my_strcpy_n(env->name_env, envp, i);
    i++;
    my_strcpy_d(env->env, envp, i);
}

env_t *addnode(env_t *temp, char **envp, int i)
{
    env_t *node;
    node = malloc(sizeof(env_t));
    node->next = NULL;
    node->env = NULL;
    node->name_env = NULL;
    node->prev = temp;
    temp->next = node;
    load_env(temp, envp[i]);
    return (node);
}

void create_list(env_t *env, char **envp, path_t *data)
{
    int len_envp = my_strlen_x(envp);
    for (int i = 0; i < len_envp; i++)
        env = addnode(env, envp, i);
    data->tail = env->prev;
}

int load_struct(env_t *env, char **envp, path_t *data)
{
    data->head = env;
    env->env = NULL;
    env->name_env = NULL;
    env->next = NULL;
    env->prev = NULL;
    create_list(env, envp, data);
}
