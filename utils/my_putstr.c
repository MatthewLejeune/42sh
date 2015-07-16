/*
** my_putstr.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 19 17:57:55 2015 Matthew LEJEUNE
** Last update Sun Apr 19 18:03:28 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
