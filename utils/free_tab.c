/*
** free_tab.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:14:20 2015 Matthew LEJEUNE
** Last update Sun May 24 18:51:02 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		free_tab(char **array)
{
  int		cur_case;

  cur_case = -1;
  while (array[++cur_case])
    free(array[cur_case]);
  free(array);
}
