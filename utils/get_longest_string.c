/*
** get_longest_string.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:47:57 2015 Matthew LEJEUNE
** Last update Tue Apr 21 09:50:15 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		get_longest_string(char *str, char *str2)
{
  int		cur_char_str;
  int		cur_char;

  cur_char = 0;
  cur_char_str = 0;
  if (str)
    while (str[cur_char])
      cur_char++;
  if (str2)
    while (str2[cur_char_str])
      cur_char_str++;
  if (cur_char >= cur_char_str)
    return (cur_char);
  else
    return (cur_char_str);
}
