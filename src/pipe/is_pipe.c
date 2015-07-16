/*
** is_pipe.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Thu Apr 30 13:34:42 2015 Matthew LEJEUNE
** Last update Thu May 28 18:22:55 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		add_a(t_cmd *lst)
{
  int		nb;

  nb = get_nb_elem(lst->params);
  if ((lst->params = my_realloc_double(lst->params, 1)) != NULL)
    lst->params[nb] = "-a";
  display_tab(lst->params);
}

int		is_pipe(t_cmd *cmd)
{
  int		cur_char;

  cur_char = -1;
  if (cmd->entire_cmd)
    while (cmd->entire_cmd[++cur_char])
      if (cmd->entire_cmd[cur_char] == '|' &&
	  cmd->entire_cmd[cur_char + 1] != '|')
	return (0);
  return (-1);
}
