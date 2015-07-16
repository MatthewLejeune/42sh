/*
** operators.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon May 11 09:25:47 2015 Matthew LEJEUNE
** Last update Mon May 11 15:57:42 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		is_operator(t_cmd *cmd)
{
  int		cur_case;

  cur_case = -1;
  while (cmd->params[++cur_case])
    {
      if (my_strcmp(cmd->params[cur_case], "&&") != -1)
	return (1);
      else if (my_strcmp(cmd->params[cur_case], "||") != -1)
	return (2);
    }
  return (-1);
}
