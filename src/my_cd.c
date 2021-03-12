/*
** EPITECH PROJECT, 2020
** my_cd
** File description:
** my cd
*/

#include "my.h"
#include "my_struct.h"

int cd_home(env_t *env, path_t *data)
{
    char *temp = NULL;

    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(env->name_env, "HOME=") != -1) {
            temp = malloc(sizeof(char) * my_strlen(env->env) + 1);
            my_strcpy(temp, env->env);
            break;
        }
        env = env->next;
    }
    env = data->head;
    change_oldpwd(env, data);
    chdir(temp);
    change_pwd(env, data);
    free(temp);
    return (0);
}

void cd_dash(env_t *env, path_t *data)
{
    char *temp = NULL;

    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(env->name_env, "OLDPWD=") != -1) {
            temp = malloc(sizeof(char) * my_strlen(env->env) + 1);
            my_strcpy(temp, env->env);
            break;
        }
        env = env->next;
    }
    env = data->head;
    change_oldpwd(env, data);
    chdir(temp);
    change_pwd(env, data);
    free(temp);
    return;
}

void simple_cd(env_t *env, path_t *data)
{
    struct stat sb;
    struct dirent *dir;
    int file = 0;

    if (stat(data->tab[1], &sb) == -1) {
        my_putstr(data->tab[1]);
        my_puts(": No such a file or directory.");
        return;
    }
    if (S_ISDIR(sb.st_mode) != 1) {
        my_putstr(data->tab[1]);
        my_puts(": Not a directory.");
        return;
    }
    change_oldpwd(env, data);
    chdir(data->tab[1]);
    change_pwd(env, data);
    return;
}

void my_cd(env_t *env, path_t *data)
{
    if (my_strlen_x(data->tab) == 1) {
        cd_home(env, data);
        return;
    }
    if (data->tab[1][0] == '-') {
        cd_dash(env, data);
        return;
    }
    if (my_strlen_x(data->tab) == 2) {
        simple_cd(env, data);
        return;
    }
}