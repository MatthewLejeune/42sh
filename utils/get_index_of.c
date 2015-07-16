/*
** get_index_of.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 27 11:31:41 2015 Matthew LEJEUNE
** Last update Mon Apr 27 11:31:47 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		get_index_of(char *str, char c)
{
  int		cur_char;

  cur_char = -1;
  while (str[++cur_char])
    if (str[cur_char] == c)
      return (cur_char);
  return (-1);
}

int		get_nindex_of(char *str, char c, int nb)
{
  int		cur_char;
  int		count;

  cur_char = -1;
  count = 0;
  while (str[++cur_char])
    if (str[cur_char] == c)
      if (++count == nb)
	return (cur_char);
  return (-1);
}
