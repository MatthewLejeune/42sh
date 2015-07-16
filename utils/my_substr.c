/*
** my_substr.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 09:47:43 2015 Matthew LEJEUNE
** Last update Mon Apr 27 11:44:24 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*my_substr(char *str, int start, int end)
{
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  if ((new_str = malloc(sizeof(char) * (end - start + 1))) == NULL)
    return (NULL);
  while (++start < end)
    new_str[++cur_char] = str[start];
  new_str[++cur_char] = '\0';
  return (new_str);
}
