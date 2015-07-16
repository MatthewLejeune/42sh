/*
** my_getnbr.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:35:47 2015 Matthew LEJEUNE
** Last update Tue Apr 21 09:55:19 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		my_char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  return (-1);
}

int		my_getnbr(char *str)
{
  int		nb;
  int		len;

  nb = 0;
  len = -1;
  if (str[0] == '-')
    len++;
  while (my_char_is_num(str[++len]) == 0)
    {
      nb += str[len] - 48;
      nb *= 10;
    }
  if (str[0] == '-')
    nb *= -1;
  return (nb / 10);
}
