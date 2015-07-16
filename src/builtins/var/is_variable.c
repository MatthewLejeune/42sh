/*
** is_variable.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Fri May  8 16:04:59 2015 Matthew LEJEUNE
** Last update Fri May  8 16:06:21 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		is_variable(t_cmd *cmd)
{
  int		cur_char;

  cur_char = get_index_of(cmd->entire_cmd, '$');
  if (cur_char == -1)
    return (-1);
  else
    return (0);
}
