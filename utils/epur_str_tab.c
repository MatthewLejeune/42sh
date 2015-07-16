/*
** epur_str_tab.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Fri May  1 10:45:09 2015 Matthew LEJEUNE
** Last update Fri May  1 10:53:14 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		**epur_str_tab(char **tab)
{
  int		cur_case;

  cur_case = -1;
  while (tab[++cur_case])
    tab[cur_case] = epur_str(tab[cur_case]);
  return (tab);
}
