/*
** change_fd.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Thu Apr 30 13:58:49 2015 Matthew LEJEUNE
** Last update Sat May 30 11:57:01 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		change_cmd_redir(t_cmd *cmd)
{
  int		index_end;
  char		*cmd_str;
  char		**new_cmd;

  if ((index_end = get_index_of(cmd->entire_cmd, '>')) == -1)
    index_end = get_index_of(cmd->entire_cmd, '<');
  cmd_str = my_substr(cmd->entire_cmd, 0, index_end);
  cmd_str = epur_str(cmd_str);
  new_cmd = my_split(cmd_str, ' ');
  cmd->name = my_strdup(new_cmd[0]);
  cmd->params = array_cpy(new_cmd);
  free(cmd_str);
  free_tab(new_cmd);
}

int		change_fd_right(t_cmd *cmd, char *filename, int redir_type)
{
  int		fd;
  int		flags;
  int		mode;

  flags = O_CREAT | O_RDWR;
  if (redir_type == 1)
    flags |= O_APPEND;
  else if (redir_type == 2)
    flags |= O_TRUNC;
  mode = S_IRUSR | S_IWUSR;
  if (filename == NULL || (fd = open(filename, flags, mode)) == -1)
    {
      print_error(filename);
      return (0);
    }
  dup2(fd, 1);
  change_cmd_redir(cmd);
  return (fd);
}

int		change_fd_left(t_cmd *cmd, char *filename)
{
  int		fd;
  int		flags;

  flags = O_RDONLY;
  if (filename == NULL || (fd = open(filename, flags)) == -1)
    {
      print_error(filename);
      return (0);
    }
  dup2(fd, 0);
  change_cmd_redir(cmd);
  return (fd);
}

int		change_fd(t_cmd *cmd, char *filename, int redir_type)
{
  if (redir_type <= 2)
    return (change_fd_right(cmd, filename, redir_type));
  else if (redir_type == 4)
    return (change_fd_left(cmd, filename));
  return (0);
}
