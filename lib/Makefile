##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for lib
##

SRC			=		my_getnbr.c \
					my_put_nbr.c \
					my_putchar.c \
					my_puts.c \
					my_putstr.c \
					my_revstr.c \
					my_show_word_array.c \
					my_str_isalpha.c \
					my_str_islower.c \
					my_str_isnum.c \
					my_str_isupper.c \
					my_str_to_word_array.c \
					my_strcapitalize.c \
					my_strcat.c \
					my_strcmp.c \
					my_strcpy.c \
					my_strdup.c \
					my_strlen.c \
					my_strlowcase.c \
					my_strncat.c \
					my_strncmp.c \
					my_strncpy.c \
					my_strstr.c \
					my_strupcase.c \
					my_atoi.c \
					count_char.c \
					my_getnbr_n.c \
					my_int_to_str.c \
					my_printf.c \
					all_flags.c \
					find_str.c \
					flags_b.c \
					flags_p.c \
					flags_up_s.c \
					manage_struct.c \
					my_intlen.c \
					my_put_float.c \
					option_special.c \
					verif_str.c

OBJ 		=		$(SRC:.c=.o)

NAME_LIB	=		libmy.a

all: compil_files create_lib

compil_files:
	@gcc -c $(SRC) -Wall -Wextra -I../include -lmy
	@echo "Compil finish"

create_lib:
	@ar cr $(NAME_LIB) $(OBJ)
	@echo "Lib create"

clean:
	@rm $(OBJ)
	@echo "all .o is remove"

fclean: clean
	@rm $(NAME_LIB)
	@echo "Lib is remove"