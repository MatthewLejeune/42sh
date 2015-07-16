/*
** my_strcmp.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat May  2 20:15:33 2015 Matthew LEJEUNE
** Last update Sat May  2 20:18:27 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		my_strcmp(char *str, char *cmp)
{
  int		cur_char;

  cur_char = -1;
  while (str[++cur_char] && cmp[cur_char])
    if (str[cur_char] != cmp[cur_char])
      return (-1);
  if (cur_char < my_strlen(str) || cur_char < my_strlen(cmp))
    return (-1);
  return (0);
}
