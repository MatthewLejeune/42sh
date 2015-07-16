/*
** variable.c for variable in /home/roy_n/PSU_2014_42sh/nathan_roy
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Tue May  5 13:52:12 2015 Nathan Roy
** Last update Sat May 23 18:45:40 2015 Nathan Roy
*/

#include "42sh.h"

void	entire_cmd_replace(t_cmd *tmp, char *save)
{
  tmp->entire_cmd = my_strreplace(tmp->entire_cmd, tmp->name, "\0");
  tmp->entire_cmd = my_strreplace(tmp->entire_cmd, "=", "\0");
  tmp->entire_cmd = my_strreplace(tmp->entire_cmd, save, "\0");
  while (tmp->entire_cmd[0] == ' ')
    tmp->entire_cmd = my_strreplace(tmp->entire_cmd, " ", "\0");
}

char	**check_set2(t_cmd *tmp, char **env, int i, int p)
{
  char	*save;

  save = &tmp->name[p + 1];
  while (env[i] != NULL && my_strncmp(tmp->name, env[i],
				      p) != 0)
    i++;
  tmp->name[p] = 0;
  if (env[i] != NULL)
    env[i] = my_strreplace(env[i], &env[i][p + 1], save);
  else
    set_var(tmp->name, save);
  entire_cmd_replace(tmp, save);
  i = 0;
  if (tmp->params[1] != NULL)
    tmp->name = tmp->params[1];
  else
    tmp->name = NULL;
  while (tmp->params[++i] != NULL)
    tmp->params[i - 1] = tmp->params[i];
  tmp->params[i - 1] = NULL;
  return (env);
}

char	**check_set(t_cmd *tmp, char **env)
{
  int	i;
  int	o;
  int	p;

  i = 0;
  o = 0;
  p = 0;
  while (tmp->name[i] != 0)
    {
      if (tmp->name[i] == '=')
	{
	  if (p == 0)
	    p = i;
	  o++;
	}
      i++;
    }
  i = 0;
  if (o == 1 && p != 0 && tmp->name[p + 1] != 0)
    env = check_set2(tmp, env, i, p);
  return (env);
}

char	**variable2(t_cmd *tmp, char **env, int i)
{
  variable_replace2(tmp, env, i);
  env = check_set(tmp, env);
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  return (env);
}

char	**variable(t_cmd *tmp, char **env)
{
  int	i;

  while (tmp->next != NULL)
    {
      i = 0;
      variable_replace2(tmp, env, i);
      env = check_set(tmp, env);
      tmp->next->prev = tmp;
      tmp = tmp->next;
    }
  env = variable2(tmp, env, i);
  return (env);
}
