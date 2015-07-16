/*
** variable3.c for variable3.c in /home/roy_n/PSU_2014_42sh/src/builtins/var
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sat May 23 18:42:53 2015 Nathan Roy
** Last update Sat May 23 18:46:29 2015 Nathan Roy
*/

#include "42sh.h"

char    *variable_replace4(char *str, char **env, int p)
{
  t_var *tmp;
  int   i;

  tmp = var_save(GET, NULL);
  if (str[1] == 0)
    return (NULL);
  str = &str[1];
  while (str[p] != 0 && str[p] != '$')
    p++;
  if (str[p] == 0)
    p = -1;
  i = 0;
  if (tmp)
    {
      if (p != -1)
        while (tmp != NULL && my_strncmp(str, tmp->name, p) != 0)
          tmp = tmp->next;
      else
        while (tmp != NULL && my_strcmp(str, tmp->name) != 0)
          tmp = tmp->next;
      if (tmp != NULL)
        return (tmp->var);
    }
  return (variable_replace5(str, env, i, p));
}

char    *variable_replace(char *str, char **env)
{
  int   i;
  char  *str2;
  int   p;

  i = 0;
  if ((str2 = variable_replace4(&str[i], env, 0)) == NULL)
    return (NULL);
  i++;
  env = env;
  while (str[i] != 0 && (p = get_index_char('$', &str[i])) != -1)
    {
      i = i + p;
      if (variable_replace4(&str[i], env, 0) == NULL)
        return (str2);
      str2 = my_strcat(str2, variable_replace4(&str[i], env, 0));
      i++;
    }
  return (str2);
}

void    replace_entire_cmd(t_cmd *tmp, char **env, int i, char *str)
{
  if (variable_replace(str, env) != NULL)
    {
      tmp->entire_cmd = my_strreplace(tmp->entire_cmd, str,
                                      variable_replace(str,
                                                       env));
      tmp->params[i] = my_strreplace(tmp->params[i], str,
                                     variable_replace(str,
                                                      env));
    }
  else
    {
      tmp->entire_cmd = my_strreplace(tmp->entire_cmd, str, "\0");
      tmp->params[i] = my_strreplace(tmp->params[i], str, "\0");
    }
}

void    variable_replace3(t_cmd *tmp, char **env, char *str)
{
  int   p;

  if (tmp->name != NULL && tmp->name[0] != 0 && get_index_char('$', tmp->name)
      != -1)
    {
      str = my_strdup(&tmp->name[get_index_char('$', tmp->name)]);
      while ((p = get_index_char(':', str)) != -1)
        {
          str[p] = 0;
          if (variable_replace(str, env) != NULL)
            tmp->name = my_strreplace(tmp->name, str, variable_replace(str,
								       env));
          else
            tmp->name = my_strreplace(tmp->name, str, "\0");
          str = &str[p + 1];
          str = &str[get_index_char('$', str)];
        }
      if (variable_replace(str, env) != NULL)
        tmp->name = my_strreplace(tmp->name, str, variable_replace(str, env));
      else
        tmp->name = my_strreplace(tmp->name, str, "\0");
    }
}

void    variable_replace2(t_cmd *tmp, char **env, int i)
{
  char  *str;
  int   p;

  i = 0;
  while (tmp->params[i] != NULL)
    {
      while (tmp->params[i] != NULL && get_index_char('$', tmp->params[i])
             == -1)
        i++;
      if (tmp->params[i] != NULL)
        {
          str = my_strdup(&tmp->params[i][get_index_char('$',
							 tmp->params[i])]);
          while ((p = get_index_char(':', str)) != -1)
            {
              str[p] = 0;
              replace_entire_cmd(tmp, env, i, str);
              str = &str[p + 1];
              str = &str[get_index_char('$', str)];
            }
          replace_entire_cmd(tmp, env, i, str);
          i++;
        }
    }
  variable_replace3(tmp, env, str);
}
