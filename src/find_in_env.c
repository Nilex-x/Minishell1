/*
** EPITECH PROJECT, 2020
** find_in_env
** File description:
** find in env
*/

#include "my.h"
#include "my_struct.h"

int load_cmd(char *str, path_t *data, char **envp)
{
    char *path_cmd = NULL;
    int malloc_size = (my_strlen(str) + my_strlen(data->cmd) + 2);
    int d = 0;

    path_cmd = malloc(sizeof(char) * malloc_size);
    for (int i = 0; i < my_strlen(str); i++) {
        path_cmd[d] = str[i];
        d++;
    }
    path_cmd[d] = '/';
    d++;
    for (int i = 0; i < my_strlen(data->cmd); i++) {
        path_cmd[d] = data->cmd[i];
        d++;
    }
    path_cmd[d] = '\0';
    exec_cmd(path_cmd, data->tab, envp);
    free(path_cmd);
}

int verif_in_directory(char *str, path_t *data, char **envp)
{
    struct dirent *dir;
    DIR *fichier = opendir(str);

    if (fichier == NULL) {
        my_putstr(data->cmd);
        my_puts(": Command not found.");
        return (0);
    }
    dir = readdir(fichier);
    while (dir != NULL) {
        if (dir->d_name[0] != '.') {
            if (my_strcmp(dir->d_name, data->cmd) != -1) {
                load_cmd(str, data, envp);
                closedir(fichier);
                return (0);
            }
        }
        dir = readdir(fichier);
    }
    closedir(fichier);
    return (1);
}

int find_in_path(path_t *data, env_t *env, char **envp)
{
    int i = 0;
    int verif = 0;
    char *path = NULL;
    while (i < my_strlen(env->env)) {
        path = my_pathcpy(i, env);
        if (verif_in_directory(path, data, envp) == 0) {
            free(path);
            return (0);
        }
        i += my_strlen(path);
        free(path);
        i++;
    }
    my_putstr(data->cmd);
    my_puts(": Command not found.");
    return (0);
}

int find_in_env(path_t *data, env_t *env, char **envp)
{
    env = data->head;
    while (env->next != NULL) {
        if (my_strcmp(env->name_env, "PATH=") == 0) {
            find_in_path(data, env, envp);
            return (0);
        }
        env = env->next;
    }
}