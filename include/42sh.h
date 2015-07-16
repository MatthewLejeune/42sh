/*
** 42sh.h for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Fri Apr 17 10:33:19 2015 Matthew LEJEUNE
** Last update Sat May 30 12:41:59 2015 Matthew LEJEUNE
*/

#ifndef __42SH__
#define __42SH__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct		s_cmd
{
  char			*name;
  char			**params;
  char			*entire_cmd;
  struct s_cmd		*next;
  struct s_cmd		*prev;
}t_cmd;

typedef struct		s_history
{
  int			index;
  char			*line;
} t_history;

typedef struct		s_var
{
  char			*name;
  char			*var;
  struct s_var		*next;
  struct s_var		*prev;
} t_var;

typedef struct		s_aliases
{
  char			*name;
  char			*cmd;
  int			checked;
  struct s_aliases	*next;
  struct s_aliases	*prev;
} t_aliases;

/*
** DEFINE_LIST_ALIAS
*/
#define GET 1
#define SET 2
#define FREE 3
/*
** END DEFINE_LIST_ALIAS
*/

/*
** DEFINE COLORS
*/
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define WHITE "\x1b[39m"
#define B_U "\x1b[1;4m"
#define CLEAR "\033\143"
#define RESET "\x1b[0m"

/*
** END DEFINE_COLORS
*/

/*
** DEFINE_CHAR_CHECK
*/

#define ECHO 1

/*
** END DEFINE_CHAR_CHECK
*/

t_cmd           *prep_pipe(t_cmd *cmd);
char    **variable2(t_cmd *tmp, char **env, int i);
char    **check_set(t_cmd *tmp, char **env);
char    **check_set2(t_cmd *tmp, char **env, int i, int p);
void    entire_cmd_replace(t_cmd *tmp, char *save);
void    variable_replace2(t_cmd *tmp, char **env, int i);
void    variable_replace3(t_cmd *tmp, char **env, char *str);
void    replace_entire_cmd(t_cmd *tmp, char **env, int i, char *str);
char    *variable_replace(char *str, char **env);
char    *variable_replace4(char *str, char **env, int p);
char    *variable_replace5(char *str, char **env, int i, int p);
void    set_var(char *name, char *val);
t_var   *set_var_initiat(char *name, char *val, t_var *var);
t_var   *var_save(int flags, t_var *new_cmd);
int     get_index_char(char c, char *str);
int		echo(t_cmd *cmd, char ***env);
void            exec_operator_or(t_cmd *cmd, char **path, char **env);
void            exec_operator_and(t_cmd *cmd, char **path, char **env);
int		exec_cmd(t_cmd *, char **);
int		my_strlen(char *);
void		my_putchar(char);
void		my_putstr(char *);
char		**array_cpy(char **);
void		free_tab(char **);
int		get_nb_elem(char **);
char		**my_split(char *, char);
char		*my_realloc(char *, int);
void		display_tab(char **);
char		*my_strcat(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_substr(char *, int, int);
char		**get_path(char **);
void		print_error(char *);
int		my_exit(t_cmd *, char ***);
int		cd(t_cmd *, char ***);
int		my_setenv(t_cmd *, char ***);
int		my_unsetenv(t_cmd *, char ***);
int		display_env(t_cmd *, char ***);
int		check_builtins(t_cmd *, char **);
int		my_getnbr(char *);
void		fill_func_ptr(int (*[7])(t_cmd *, char ***));
int		get_longest_string(char *, char *);
char		*my_memset(char *, char, int);
int		get_index_elem_env(char *, char **);
char		**my_realloc_double(char **, int);
char		**my_memset_double(char **, char *, int);
char		*get_env_var(char *, char **);
char		*my_strdup(char *);
t_aliases	*get_list_alias(int, t_aliases *);
char		**get_conf_file();
int		is_alias(char *);
int		check_alias(char *, int);
int		get_index_of(char *, char);
int		get_nindex_of(char *, char, int);
char		**get_alias(char *);
int		add_aliases();
int		add_new_alias(t_aliases **, char *, char *);
int		display_alias_list(t_aliases *);
void		free_alias(t_aliases *);
int		add_cmd(t_cmd **, char *, char **, char *);
void		show_cmd_list(t_cmd *);
void		free_cmd_list(t_cmd *);
char		*my_strreplace(char *, char *, char *);
t_cmd		*get_entire_cmd(t_cmd *);
void		my_echo(t_cmd *, char ***);
void		wait_char(t_cmd *);
int		is_redirection(char *);
int		is_pipe(t_cmd *);
char		*get_filename(char *);
int		get_index_elem(char **, char *);
int		change_fd(t_cmd *, char *, int);
char		*epur_str(char *);
int		prep_exec_pipe(t_cmd *, char **, char **);
void		exec_pipe(t_cmd *, char **, char **, int);
int		prep_exec(t_cmd *, char **, char **);
char		**epur_str_tab(char **);
int		prep_double_left_redir(t_cmd *, char **, char **);
int		my_strcmp(char *, char *);
void		change_cmd_redir(t_cmd *);
int		check_double_left_redir(t_cmd *);
void		add_a(t_cmd *);
t_cmd		*get_set_list_cmd_redir(int, t_cmd *);
void		sig_def_shell();
void		sig_def_exec();
char		**variable(t_cmd *, char **);
int		is_variable(t_cmd *);
int		is_operator(t_cmd *);
int		get_the_nbr(char *);
char		*prev_cmd(char *, int);
char		*prev_cmd_2(char **, int, int);
char		**get_history_tab(int, char **);
int		write_history(char *, char **, int, int);
char		*my_strcpy(char *, char *);
void		print_history(t_cmd *, char ***);
int		check_history(char *);
void		exec_before(t_cmd *, int *, char **);
void		get_fd(t_cmd *, char *, int *);
void		change_dup(int *);

#endif
