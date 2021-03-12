/*
** EPITECH PROJECT, 2020
** add_envp
** File description:
** add var in linked list
*/

#include "my.h"
#include "my_struct.h"

env_t *addnode_name_env(env_t *temp, int len_name, path_t *data)
{
    env_t *node;

    node = malloc(sizeof(env_t));
    temp->next = node;
    node->next = NULL;
    node->env = NULL;
    node->prev = temp;
    node->name_env = malloc(sizeof(char) * len_name + 2);
    node->name_env = my_strcpy(node->name_env, data->tab[1]);
    node->name_env[len_name] = '=';
    node->name_env[len_name + 1] = '\0';
    return (node);
}

void create_name_env(env_t *env, path_t *data)
{
    int len_name = my_strlen(data->tab[1]);
    char *temp = NULL;
    if (verif_same_name_var(data, env) == 0) {
        env = data->tail;
        env = addnode_name_env(env, len_name, data);
        data->tail = env;
    } else {
        temp = malloc(sizeof(char) * len_name + 2);
        temp = my_strcpy(temp, data->tab[1]);
        temp[len_name] = '=';
        temp[len_name + 1] = '\0';
        env = data->head;
        while (env->next != NULL) {
            if (my_strcmp(temp, env->name_env) != -1) {
                free(env->env);
                env->env = NULL;
            }
            env = env->next;
        }
        free(temp);
    }
}

env_t *addnode_env(env_t *temp, path_t *data, int len_name, int len_env)
{
    env_t *node;
    node = malloc(sizeof(env_t));
    node->next = NULL;
    node->prev = temp;
    temp->next = node;
    node->name_env = malloc(sizeof(char) * len_name + 2);
    node->name_env = my_strcpy(node->name_env, data->tab[1]);
    node->name_env[len_name] = '=';
    node->name_env[len_name + 1] = '\0';
    node->env = malloc(sizeof(char) * len_env + 2);
    node->env = my_strcpy(node->env, data->tab[2]);
    return (node);
}

void create_env(env_t *env, path_t *data)
{
    char *temp = NULL;
    int len_name = my_strlen(data->tab[1]);
    int len_env = 0;

    if (verif_same_name_var(data, env) == 0) {
        len_env = my_strlen(data->tab[2]);
        env = data->tail;
        env = addnode_env(env, data, len_name, len_env);
        data->tail = env;
    } else
        change_var_cotent(env, data, len_name);
}

void add_envp(env_t *env, path_t *data)
{
    if (data->cols == 2) {
        create_name_env(env, data);
        return;
    }
    if (data->cols == 3) {
        create_env(env, data);
        return;
    }
    if (data->cols > 3) {
        my_puts("setenv: Too many arguments.");
        return;
    }
}