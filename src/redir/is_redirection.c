/*
** is_redirection.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Thu Apr 30 13:39:17 2015 Matthew LEJEUNE
** Last update Thu Apr 30 18:00:56 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		check_redir(char *cmd)
{
  int		cur_char;

  if ((cur_char = get_index_of(cmd, '>')) != -1)
    {
      if (cmd[cur_char + 1] == '>')
	return (1);
      else
	return (2);
    }
  else if ((cur_char = get_index_of(cmd, '<')) != -1)
    {
      if (cmd[cur_char + 1] == '<')
	return (3);
      else
	return (4);
    }
  return (-1);
}

int		is_redirection(char *cmd)
{
  int		cur_char;

  cur_char = -1;
  if (cmd)
    while (cmd[++cur_char])
      if (cmd[cur_char] == '>' || cmd[cur_char] == '<')
	     return (check_redir(cmd));
  return (-1);
}
