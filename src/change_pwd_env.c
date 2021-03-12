/*
** EPITECH PROJECT, 2020
** change_pwd_env.c
** File description:
** change pwd env
*/

#include "my.h"
#include "my_struct.h"

void change_pwd(env_t *env, path_t *data)
{
    char *path = NULL;

    path = getcwd(path, 150);
    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(env->name_env, "PWD=") != -1) {
            env->env = malloc(sizeof(char) * (my_strlen(path) + 1));
            my_strcpy(env->env, path);
        }
        env = env->next;
    }
    free(path);
}

void change_oldpwd(env_t *env, path_t *data)
{
    char *path = NULL;

    path = getcwd(path, 150);
    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(env->name_env, "OLDPWD=") != -1) {
            env->env = malloc(sizeof(char) * (my_strlen(path) + 1));
            my_strcpy(env->env, path);
        }
        env = env->next;
    }
    free(path);
}