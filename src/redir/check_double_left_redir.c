/*
** check_double_left_redir.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat May  2 20:52:42 2015 Matthew LEJEUNE
** Last update Sat May 30 15:50:55 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		check_double_left_redir(t_cmd *cmd)
{
  int		cur_case;
  t_cmd		*search;

  search = cmd;
  cur_case = -1;
  while (search->entire_cmd[++cur_case])
    if (search->entire_cmd[cur_case] == '<' &&
	search->entire_cmd[cur_case + 1] == '<')
      return (0);
  return (-1);
}
