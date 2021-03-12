/*
** EPITECH PROJECT, 2020
** find_command.c
** File description:
** find command
*/

#include "my.h"
#include "my_struct.h"

void exec_cmd(char *cmd, char **arg, char **envp)
{
    int pid_c = 0;
    pid_t pid = fork();
    int return_exec = 0;

    if (pid == 0) {
        pid_c = getpid();
        return_exec = execve(cmd, arg, envp);
        if (return_exec == -1)
            kill(pid_c, SIGKILL);
        if (return_exec == SIGINT) {
            my_puts("Segmentation fault (core dumped)");
            kill(pid_c, SIGINT);
        }
        exit(0);
    }
    wait(NULL);
    return;
}

int verify_cmd(path_t *data)
{
    int i = 0;

    while (data->cmd[i] != '\0') {
        if (data->cmd[i] == '/')
            return (1);
        i++;
    }
    return (0);
}

int find_command(path_t *data, env_t *env)
{
    char **envp = update_envp(data, env, envp);
    int verif = verify_cmd(data);

    if (verif == 0) {
        find_in_env(data, env, envp);
        return (0);
    }
    if (verif == 1)
        exec_cmd(data->cmd, data->tab, envp);
    return (0);
}