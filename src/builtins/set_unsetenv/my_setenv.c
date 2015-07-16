/*
** my_setenv.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:24:42 2015 Matthew LEJEUNE
** Last update Sat May 30 11:29:03 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		set_exist(t_cmd *cmds, char ***env, int var_pos)
{
  char		*add;
  char		*var;
  char		*str;

  if (cmds->params[1] && cmds->params[2])
    add = cmds->params[2];
  else
    return (-1);
  var = my_substr((*env)[var_pos], -1, get_index_of((*env)[var_pos], '=') + 1);
  str = my_strcat(var, add);
  if (((*env)[var_pos] = my_realloc(my_strdup((*env)[var_pos]),
				    my_strlen(add))) == NULL)
    return (0);
  (*env)[var_pos] = my_strdup(str);
  free(var);
  free(add);
  free(str);
  return (0);
}

int		set_new(t_cmd *cmds, char ***env)
{
  char		*var;
  char		*temp;
  int		cur_case;

  cur_case = -1;
  if (cmds->params[1])
    temp = my_strcat(cmds->params[1], "=");
  else
    {
      fprintf(stderr, RED"setenv : too few arguments\n"RESET);
      return (0);
    }
  if (cmds->params[2])
    var = my_strcat(temp, cmds->params[2]);
  while ((*env)[++cur_case]);
  (*env)[cur_case++] = var;
  (*env)[cur_case] = NULL;
  free(temp);
  return (0);
}

int		my_setenv(t_cmd *cmds, char ***env)
{
  int		var_pos;

  if (!cmds->params[1])
    {
      fprintf(stderr, RED"usage : setenv [VAR] [VALUE]\n"RESET);
      return (-1);
    }
  if (!cmds->params[2])
    {
      fprintf(stderr, RED"usage : setenv [VAR] [VALUE]\n"RESET);
      return (-1);
    }
  if ((var_pos = get_index_elem_env(cmds->params[1], *env)) != -1)
    set_exist(cmds, env, var_pos);
  else
    set_new(cmds, env);
  return (0);
}
