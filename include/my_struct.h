/*
** EPITECH PROJECT, 2021
** my_struct
** File description:
** header
*/

#ifndef MY_STRUCT
#define MY_STRUCT

typedef struct path {
    char *cmd;
    char *str;
    char **tab;
    int cols;
    struct env *head;
    struct env *tail;
} path_t;

typedef struct env {
    char *env;
    char *name_env;
    struct env *next;
    struct env *prev;
}env_t;

int verif_same_name_var(path_t *data, env_t *env);
void change_var_cotent(env_t *env, path_t *data, int len_name);
char **update_envp(path_t *data, env_t *env, char **envp);
int find_in_env(path_t *data, env_t *env, char **envp);
void exec_cmd(char *cmd, char **arg, char **envp);
char *my_pathcpy(int i, env_t *env);
void display_env(env_t *env, path_t *data);
void add_envp(env_t *env, path_t *data);
void my_cd(env_t *env, path_t *data);
int my_unsetenv(path_t *data, env_t *env);
void all_free(path_t *data);
void display_path(env_t *env, path_t *data);
int find_command(path_t *data, env_t *env);
void init_data(path_t *data);
int load_struct(env_t *env, char **envp, path_t *data);
void free_linked_list(env_t *env, path_t *data);
void change_oldpwd(env_t *env, path_t *data);
void change_pwd(env_t *env, path_t *data);

#endif /* !MY_STRUCT */