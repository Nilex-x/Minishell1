/*
** EPITECH PROJECT, 2020
** display_path
** File description:
** display path
*/

#include "my.h"
#include "my_struct.h"

void display_path(env_t *env, path_t *data)
{
    char *path = NULL;
    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(env->name_env, "USER=") == 0)
            my_putstr(env->env);
        env = env->next;
    }
    path = getcwd(path, 100);
    my_putstr(path);
    my_putstr("> ");
    signal(SIGINT, SIG_IGN);
}