/*
** my_putchar.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 19 17:57:12 2015 Matthew LEJEUNE
** Last update Sun Apr 19 17:57:43 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
