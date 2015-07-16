/*
** signals.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue May  5 11:07:00 2015 Matthew LEJEUNE
** Last update Thu May 28 16:40:37 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		signal_handler(int sig)
{
  sig = sig;
  my_putchar('\n');
}

void		sig_def_shell()
{
  signal(SIGTSTP, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTERM, SIG_IGN);
}

void		print_segfault()
{
  my_putstr("segmentation fault (core dumped)\n");
}

void		sig_def_exec()
{
  signal(SIGTSTP, SIG_DFL);
  signal(SIGINT, SIG_DFL);
  signal(SIGQUIT, SIG_DFL);
}
