##
## Makefile for 42sh in /home/lejeun_m/42sh
## 
## Made by Matthew LEJEUNE
## Login   <lejeun_m@epitech.net>
## 
## Started on  Sun Apr 19 17:42:27 2015 Matthew LEJEUNE
## Last update Sat May 30 12:34:41 2015 Matthew LEJEUNE
##

SRC_42=		src/base/42sh.c \
		src/base/exec_cmd.c \
		src/list/lst_cmd_functions.c \
		src/list/lst_aliases_func.c \
		src/base/get_path.c \
		src/builtins/exit/my_exit.c \
		src/builtins/misc/check_builtins.c \
		src/builtins/cd/cd.c \
		src/builtins/misc/display_env.c \
		src/builtins/set_unsetenv/my_setenv.c \
		src/builtins/set_unsetenv/my_unsetenv.c \
		src/builtins/misc/fill_func_ptr.c \
		src/base/get_index_elem_env.c \
		src/base/get_env_var.c \
		src/conf/get_conf_file.c \
		src/conf/parser/check_aliases.c \
		src/conf/add_alias.c \
		src/conf/use_alias.c \
		src/redir/is_redirection.c \
		src/redir/get_set_list_cmd_redir.c \
		src/pipe/is_pipe.c \
		src/pipe/prep_pipe.c \
		src/redir/get_filename_redir.c \
		src/redir/change_fd.c \
		src/pipe/exec_pipe.c \
		src/redir/double_left_redir.c \
		src/redir/check_double_left_redir.c \
		src/base/signals.c \
		src/builtins/echo/echo.c \
		src/builtins/var/variable.c \
		src/builtins/var/variable2.c \
		src/builtins/var/variable3.c \
		src/builtins/var/is_variable.c \
		src/operators/operators.c \
		src/operators/exec_operator.c \
		src/base/dup.c

SRC_UTILS=	utils/get_next_line.c \
		utils/my_putchar.c \
		utils/my_putstr.c \
		utils/my_strlen.c \
		utils/free_tab.c \
		utils/array_cpy.c \
		utils/get_nb_elem.c \
		utils/my_split.c \
		utils/my_realloc.c \
		utils/debug/display_tab.c \
		utils/my_strcat.c \
		utils/my_strncmp.c \
		utils/my_substr.c \
		utils/my_getnbr.c \
		utils/get_longest_string.c \
		utils/my_memset.c \
		utils/my_strdup.c \
		utils/get_index_of.c \
		utils/my_strreplace.c \
		utils/get_cmd.c \
		utils/get_index_elem.c \
		utils/epur_str.c \
		utils/epur_str_tab.c \
		utils/my_strcmp.c \
		utils/my_strcpy.c

SRC_TEST=	test/main.c

OBJ_42=		$(SRC_42:.c=.o)
OBJ_UTILS=	$(SRC_UTILS:.c=.o)
OBJ_TEST=	$(SRC_TEST:.c=.o)

NAME=		42sh
NAME_TEST=	test
CC=		cc
CFLAGS=		-Wall -Werror -Wextra -pedantic -ansi -g3
CFLAGS+=	-I include/

all:	$(NAME)

$(NAME): 	$(OBJ_42) $(OBJ_UTILS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ_42) $(OBJ_UTILS)

test:		$(OBJ_TEST)
		$(CC) $(CFLAGS) -o test/$(NAME_TEST) $(OBJ_TEST) $(OBJ_UTILS)

clean:
	rm -rf $(OBJ_42) $(OBJ_UTILS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

