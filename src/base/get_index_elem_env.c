/*
** get_index_elem_env.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Wed Apr 22 08:22:53 2015 Matthew LEJEUNE
** Last update Wed Apr 22 08:24:50 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		get_index_elem_env(char *var, char **env)
{
  int		cur_case;

  cur_case = -1;
  while (env[++cur_case])
    if (my_strncmp(var, env[cur_case], my_strlen(var)) == 0)
      return (cur_case);
  return (-1);
}
