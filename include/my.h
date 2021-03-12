/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef MY
#define MY

#define _GNU_SOURCE
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct
{
    va_list list;
    char *o;
    char p;
    int nb;
    char *s;
    int flags_n;
    int len_print;
} flags_t;

int my_atoi(char *str);
int my_getnbr_n(char *str, int n);
int my_getnbr(char *str);
char *my_int_to_str(int nb);
int my_put_nbr(long int nb);
void my_putchar(char c);
void my_putchar_error(char c);
void my_puts(char *str);
int my_putstr(char *str);
char *my_revstr(char *str);
int my_show_word_array(char * const *tab);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void flags_o(flags_t *data, ...);
void flags_x(flags_t *data, ...);
void flags_up_x(flags_t *data, ...);
void init_data_printf(flags_t *data);
void free_all(char **flags, flags_t *data);
int count_char_in_str(char c, char *to_find);
int verif_str(char *str, flags_t *data);
void find_last_char(char *str, int len);
int count_char_str(char *str, char c);
void separate_flags(char flags_letter, flags_t *data);
int pointer_function(char *flags, flags_t *data);
void flags_u(flags_t *data, ...);
int my_printf(char *str, ...);
void flags_up_s(flags_t *data, ...);
int my_compute_power_it(int nb, int p);
void flags_b(flags_t *data, ...);
void flags_p(flags_t *data, ...);
int my_intlonglen(unsigned long int nb);
int my_compute_power_it_long(unsigned long int nb, int p);
void flags_s(flags_t *data, ...);
void flags_c(flags_t *data, ...);
void flags_d(flags_t *data, ...);
void sort_flags(char *flags, flags_t *data);
int option_special(char *flags, flags_t *data);
void flags_f(flags_t *data, ...);
void my_put_float(double nb);
int my_intlen(int nb);
char *my_strcpy_d(char *dest, char const *src, int i);
char *my_strcpy_n(char *dest, char const *src , int n);
int my_strlen_n(char const *str, int i);
int my_strlen_path(char *str, int i);
int my_strlen_x(char **tab);
int my_putstr_n(char *str , int i);

#endif /* !MY */