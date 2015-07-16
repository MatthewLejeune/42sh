/*
** my_memset.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 10:50:30 2015 Matthew LEJEUNE
** Last update Wed Apr 22 10:04:18 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*my_memset(char *str, char c, int size)
{
  int		cur_char;

  cur_char = -1;
  while (++cur_char < size)
    {
      str[cur_char] = c;
    }
  return (str);
}

char		**my_memset_double(char **tab, char *str, int size)
{
  int		cur_case;

  cur_case = -1;
  while (++cur_case < size)
    {
      tab[cur_case] = str;
    }
  return (tab);
}
