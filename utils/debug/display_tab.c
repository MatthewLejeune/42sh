/*
** display_tab.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:33:41 2015 Matthew LEJEUNE
** Last update Mon Apr 20 08:36:57 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		display_tab(char **array)
{
  int		cur_case;

  cur_case = -1;
  while (array[++cur_case])
    printf("%s\n", array[cur_case]);
}
