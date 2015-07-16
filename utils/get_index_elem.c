/*
** get_index_elem.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Apr 30 14:50:17 2015 Matthew LEJEUNE
** Last update Sun May 24 13:08:53 2015 Nathan Roy
*/

#include "42sh.h"

int		get_index_elem(char **tab, char *str)
{
  int		cur_case;

  cur_case = -1;
  while (tab[++cur_case])
    if (my_strncmp(tab[cur_case], str,
		   get_longest_string(tab[cur_case], str)) == 0)
      return (cur_case);
  return (-1);
}
