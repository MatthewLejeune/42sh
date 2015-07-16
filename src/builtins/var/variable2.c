/*
** variable2.c for variable2.c in /home/roy_n/PSU_2014_42sh/src/builtins/var
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sat May 23 18:41:01 2015 Nathan Roy
** Last update Sat May 23 18:42:04 2015 Nathan Roy
*/

#include "42sh.h"

int     get_index_char(char c, char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0 && str[i] != c)
    i++;
  if (str[i] == 0)
    return (-1);
  return (i);
}

t_var   *var_save(int flags, t_var *new_cmd)
{
  static t_var  *cmd = NULL;

  if (flags == GET)
    return (cmd);
  else if (flags == SET)
    cmd = new_cmd;
  return (NULL);
}

t_var   *set_var_initiat(char *name, char *val, t_var *var)
{
  if ((var = malloc(sizeof(t_var))) == NULL)
    return (NULL);
  var->name = name;
  var->var = val;
  var->next = NULL;
  var->prev = NULL;
  return (var);
}

void    set_var(char *name, char *val)
{
  t_var *var;
  t_var *tmp;

  tmp = var_save(GET, NULL);
  var = set_var_initiat(name, val, NULL);
  if (tmp != NULL)
    {
      while (tmp->next != NULL && my_strcmp(tmp->name, name) != 0)
        tmp = tmp->next;
      if (my_strcmp(tmp->name, name) != 0)
        {
          tmp->next = var;
          var->prev = tmp;
        }
      else
        tmp->var = val;
      while (tmp->prev != NULL)
        tmp = tmp->prev;
      var_save(SET, tmp);
    }
  else
    var_save(SET, var);
}

char    *variable_replace5(char *str, char **env, int i, int p)
{
  if (p != -1)
    {
      str[p] = '=';
      while (env[i] != NULL && my_strncmp(str, env[i], p) != 0)
        i++;
      str[p] = '$';
    }
  else
    {
      str = my_strcat(str, "=");
      while (env[i] != NULL && my_strncmp(str, env[i], my_strlen(str)) != 0)
        i++;
    }
  if (env[i] != NULL)
    return (&env[i][my_strlen(str)]);
  return (NULL);
}
