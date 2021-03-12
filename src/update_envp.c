/*
** EPITECH PROJECT, 2020
** update_envp
** File description:
** update envp
*/

#include "my.h"
#include "my_struct.h"

int count_char(env_t *env)
{
    int len_1 = my_strlen(env->name_env);
    int len_2 = my_strlen(env->env);

    return (len_1 + len_2 + 1);
}

int count_struct(env_t *env, path_t *data)
{
    int count = 0;

    env = data->head;
    while (env->next != NULL) {
        count++;
        env = env->next;
    }
    return (count);
}

void load_envp(char **envp, env_t *env, int len, int d)
{
    int p = 0;
    int i = 0;
    int len_name = my_strlen(env->name_env);

    for (; i < len; i++) {
        if (i < len_name) {
            if (env->name_env != NULL)
                envp[d][i] = env->name_env[i];
        } else {
            if (env->env != NULL)
                envp[d][i] = env->env[p];
            p++;
        }
    }
    envp[d][i] = '\0';
}

char **update_envp(path_t *data, env_t *env, char **envp)
{
    int i = 0;
    int len_env = 0;
    int len = count_struct(env, data);

    envp = malloc(sizeof(char *) * (len + 1));
    env = data->head;
    while (env->next != NULL) {
        len_env = count_char(env);
        envp[i] = malloc(sizeof(char) * (len_env + 2));
        load_envp(envp, env, len_env, i);
        env = env->next;
        i++;
        len_env = 0;
    }
    envp[len] = 0;
    return (envp);
}