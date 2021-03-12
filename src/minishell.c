/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** make minishell with cd, env, setenv, unsetenv command's
*/

#include "my.h"
#include "my_struct.h"

int sort_prog(path_t *data, env_t *env)
{
    if (my_strcmp(data->cmd, "env") == 0) {
        display_env(env, data);
        return (2);
    }
    if (my_strcmp(data->cmd, "setenv") == 0) {
        add_envp(env, data);
        return (2);
    }
    if (my_strcmp(data->cmd, "cd") == 0) {
        my_cd(env, data);
        return (2);
    }
    if (my_strcmp(data->cmd, "unsetenv") == 0) {
        my_unsetenv(data, env);
        return (2);
    }
    if (my_strcmp(data->cmd, "exit") == 0) {
        return (1);
    }
    return (0);
}

void load_all_content(path_t *data)
{
    int i = 0;

    data->tab = my_str_to_word_array(data->str);
    data->cmd = my_strdup(data->tab[0]);
    for (; data->tab[i] != NULL; i++);
    data->cols = i;
}

void getuser(env_t *env, path_t *data)
{
    size_t len = 0;
    int tmp = 0;

    all_free(data);
    display_path(env, data);
    if (getline(&data->str, &len, stdin) == -1) return;
    if (data->str[0] == '\n') {
        getuser(env, data);
        return;
    }
    data->str[my_strlen(data->str) - 1] = '\0';
    load_all_content(data);
    tmp = sort_prog(data, env);
    if (tmp == 0) {
        find_command(data, env);
        getuser(env, data);
    }
    if (tmp == 2)
        getuser(env, data);
}

int main(int argc, char **argv, char **envp)
{
    path_t data;
    env_t env;

    init_data(&data);
    load_struct(&env, envp, &data);
    getuser(&env, &data);
    my_puts("exit");
    all_free(&data);
    free_linked_list(&env, &data);
    return (0);
}