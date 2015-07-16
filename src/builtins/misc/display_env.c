/*
** display_env.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:27:05 2015 Matthew LEJEUNE
** Last update Sun May 24 22:59:44 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		display_env(t_cmd *cmds, char ***env)
{
  cmds = cmds;
  display_tab(*env);
  return (0);
}
