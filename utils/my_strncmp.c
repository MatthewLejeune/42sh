/*
** my_strncmp.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 10:30:38 2015 Matthew LEJEUNE
** Last update Sun May 24 18:25:41 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		my_strncmp(char *src, char *cmp, int length)
{
  int		cur_char;

  cur_char = -1;
  if (src && cmp)
    while (++cur_char < length && src[cur_char] && cmp[cur_char])
      if (src[cur_char] != cmp[cur_char])
	return (-1);
  if (cur_char < length)
    return (-1);
  return (0);
}
