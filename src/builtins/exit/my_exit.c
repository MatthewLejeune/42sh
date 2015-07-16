/*
** my_exit.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 08:34:19 2015 Matthew LEJEUNE
** Last update Thu May 28 16:59:34 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		print_error(char *name_cmd)
{
  fprintf(stderr, RED"%s : %s\n"RESET, name_cmd, strerror(errno));
}

int		my_exit(t_cmd *cmds, char ***env)
{
  int		return_value;

  env = env;
  if (cmds->params[1])
    return_value = my_getnbr(cmds->params[1]);
  exit(return_value);
  return (0);
}
