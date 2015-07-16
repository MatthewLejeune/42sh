/*
** dup.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat May 30 12:30:47 2015 Matthew LEJEUNE
** Last update Sat May 30 12:34:28 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		get_fd(t_cmd *cmd, char *file, int *fd)
{
  *fd = change_fd(cmd, file, is_redirection(cmd->entire_cmd));
  free(file);
}

void		change_dup(int pipefd[2])
{
  dup2(pipefd[0], 0);
  dup2(pipefd[1], 1);
  close(pipefd[0]);
  close(pipefd[1]);
}
