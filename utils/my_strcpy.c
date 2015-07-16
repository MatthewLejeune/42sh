/*
** my_strcpy.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh/src/builtins/history
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun May 24 15:52:18 2015 Matthew LEJEUNE
** Last update Sun May 24 15:56:05 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*my_strcpy(char *str, char *src)
{
  int		cur_char;

  cur_char = -1;
  while (++cur_char < my_strlen(src))
    str[cur_char] = src[cur_char];
  str[cur_char] = '\0';
  return (str);
}
