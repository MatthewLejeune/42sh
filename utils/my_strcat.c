/*
** my_strcat.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:46:27 2015 Matthew LEJEUNE
** Last update Sun May 24 19:05:52 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*my_strcat(char *src, char *dest)
{
  int		cur_char_dest;
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  cur_char_dest = -1;
  if ((new_str = malloc(sizeof(char) *
			(my_strlen(src) + my_strlen(dest) + 1))) == NULL)
    return (NULL);
  while (src[++cur_char])
    new_str[cur_char] = src[cur_char];
  while (dest[++cur_char_dest])
    {
      new_str[cur_char] = dest[cur_char_dest];
      cur_char++;
    }
  new_str[cur_char] = '\0';
  return (new_str);
}
