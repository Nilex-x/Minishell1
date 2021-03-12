/*
** EPITECH PROJECT, 2020
** init_data
** File description:
** init data
*/

#include "my.h"
#include "my_struct.h"

void init_data(path_t *data)
{
    data->cols = 0;
    data->cmd = NULL;
    data->head = NULL;
    data->str = NULL;
    data->tab = NULL;
    data->tail = NULL;
}

void free_linked_list(env_t *env, path_t *data)
{
    env_t *temp;
    int i = 0;
    env = data->tail;
    while (env->prev != NULL) {
        temp = env;
        env = env->prev;
        free(temp->name_env);
        free(temp->env);
        free(temp);
    }
    free(env->env);
    free(env->name_env);
}

void all_free(path_t *data)
{
    data->cols = 0;
    if (data->str != NULL) {
        free(data->str);
        data->str = NULL;
    }
    if (data->cmd != NULL) {
        free(data->cmd);
        data->cmd = NULL;
    }
    if (data->tab != NULL) {
        for (int i = 0; i < data->cols; i++)
            free(data->tab[i]);
        free(data->tab);
        data->tab = NULL;
    }
}

void change_var_cotent(env_t *env, path_t *data, int len_name)
{
    char *temp = NULL;
    temp = malloc(sizeof(char) * len_name + 2);
    temp = my_strcpy(temp, data->tab[1]);
    temp[len_name] = '=';
    temp[len_name + 1] = '\0';
    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(temp, env->name_env) != -1) {
            free(env->env);
            env->env = malloc(sizeof(char) * (my_strlen(data->tab[2]) + 1));
            env->env = my_strcpy(env->env, data->tab[2]);
            my_puts(data->tab[2]);
        }
        env = env->next;
    }
    free(temp);
}

int verif_same_name_var(path_t *data, env_t *env)
{
    char *temp = NULL;
    int len_name = my_strlen(data->tab[1]);
    temp = malloc(sizeof(char) * len_name + 2);
    temp = my_strcpy(temp, data->tab[1]);
    temp[len_name] = '=';
    temp[len_name + 1] = '\0';
    env = data->head;
    my_putstr(temp);
    while (env->next != NULL) {
        my_putstr(env->name_env);
        if (my_strcmp(temp, env->name_env) != -1) {
            free(temp);
            return (1);
        }
        env = env->next;
    }
    free(temp);
    return (0);
}