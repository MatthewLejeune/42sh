/*
** my_unsetenv.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:25:51 2015 Matthew LEJEUNE
** Last update Thu May 28 17:34:06 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		my_unsetenv(t_cmd *cmds, char ***env)
{
  int		var_pos;
  int		cur_char;
  int		nb_elem;

  if ((var_pos = get_index_elem_env(cmds->params[1], *env)) == -1)
    {
      fprintf(stderr, RED"Can't find %s var\n"RESET, cmds->params[1]);
      return (-1);
    }
  cur_char = var_pos;
  nb_elem = get_nb_elem(*env);
  if (cur_char == (nb_elem - 1))
    (*env)[cur_char] = NULL;
  else
    while (++cur_char < nb_elem)
      {
	(*env)[cur_char - 1] = (*env)[cur_char];
	(*env)[cur_char] = NULL;
      }
  return (0);
}
