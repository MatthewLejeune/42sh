/*
** fill_func_ptr.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:13:55 2015 Matthew LEJEUNE
** Last update Sun May 24 22:56:19 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		fill_func_ptr(int (*fptr[6])(t_cmd *, char ***))
{
  fptr[0] = &cd;
  fptr[1] = &my_exit;
  fptr[2] = &my_setenv;
  fptr[3] = &my_unsetenv;
  fptr[4] = &display_env;
  fptr[5] = &echo;
}
