/*
** get_set_list_cmd_redir.c for get_set_list_cmd_redir.c in /home/roy_n/PSU_2014_42sh/src/redir
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sun May 24 13:06:10 2015 Nathan Roy
** Last update Sun May 24 13:06:49 2015 Nathan Roy
*/

#include "42sh.h"

t_cmd           *get_set_list_cmd_redir(int flags, t_cmd *new_cmd)
{
  static t_cmd  *cmd = NULL;

  if (flags == GET)
    return (cmd);
  else if (flags == SET)
    cmd = new_cmd;
  else if (flags == FREE)
    {
      free_cmd_list(cmd);
      cmd = NULL;
    }
  return (NULL);
}
