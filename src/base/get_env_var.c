/*
** get_env_var.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Apr 22 08:12:23 2015 Matthew LEJEUNE
** Last update Sat May 23 18:19:19 2015 Nathan Roy
*/

#include "42sh.h"

char		*get_env_var(char *var, char **env)
{
  int		cur_case;

  cur_case = -1;
  var = my_strcat(var, "=");
  while (env[++cur_case])
    if (my_strncmp(var, env[cur_case], my_strlen(var)) == 0)
      return (my_substr(env[cur_case], my_strlen(var) - 1,
			my_strlen(env[cur_case])));
  return (NULL);
}
