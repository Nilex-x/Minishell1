##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for do-op
##

SRC			=		src/add_envp.c \
					src/change_pwd_env.c \
					src/display_env.c \
					src/display_path.c \
					src/find_command.c \
					src/find_in_env.c \
					src/init_data.c \
					src/load_struct.c \
					src/minishell.c \
					src/my_cd.c \
					src/my_pathcpy.c \
					src/my_unsetenv.c \
					src/update_envp.c \


LIB_PATH	=		lib

NAME_LIB	=		libmy.a

PATH_MAKE	=		lib

BIN_NAME	=		my_sh

PATH_INCLUDE	=	include

all: compil_lib create_bin

compil_lib:
	@make -C $(PATH_MAKE)

create_bin:
	@gcc -o $(BIN_NAME) $(SRC) -L$(LIB_PATH) -I$(PATH_INCLUDE) -lmy
	@echo "binary create"

clean:
	@make clean -C $(PATH_MAKE)

fclean:
	@make fclean -C $(PATH_MAKE)
	@rm $(BIN_NAME)
	@echo "binary remove"

re: fclean all