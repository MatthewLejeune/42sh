/*
** my_strdup.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat Apr 25 15:33:04 2015 Matthew LEJEUNE
** Last update Sat Apr 25 15:37:31 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*my_strdup(char *str)
{
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  new_str = my_memset(new_str, '\0', my_strlen(str) + 1);
  while (str[++cur_char])
    new_str[cur_char] = str[cur_char];
  return (new_str);
}
