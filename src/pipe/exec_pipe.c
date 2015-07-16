/*
** exec_pipe.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Thu Apr 30 15:58:17 2015 Matthew LEJEUNE
** Last update Thu May 28 19:46:00 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		exec_pipe_cmd(t_cmd *pipe_list, char **path, char **env)
{
  pipe_list = pipe_list->next;
  if (pipe_list && pipe_list->next != NULL)
    exec_pipe(pipe_list, path, env, 1);
  return (exec_cmd(pipe_list, env));
}

void		exec_parent_process(t_cmd *pipe_list, char **path,
				    char **env, int *pipefd)
{
  int		status;

  wait(&status);
  if (status == 139)
    fprintf(stderr, "Segmentation fault\n");
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    {
      print_error(pipe_list->name);
      exit(1);
    }
  status += exec_pipe_cmd(pipe_list, path, env);
  close(pipefd[0]);
  exit(status);
}

void		exec_child_process(t_cmd *pipe_list, char **path,
				   char **env, int *pipefd)
{
  int	status;

  path = path;
  status = 0;
  close(pipefd[0]);
  if (dup2(pipefd[1], 1) == -1)
    {
      print_error(pipe_list->name);
      exit(1);
    }
  status = exec_cmd(pipe_list, env);
  close(pipefd[1]);
  exit(status);
}

void		exec_pipe(t_cmd *cmd, char **path, char **env, int nb)
{
  pid_t		pid;
  int		pipefd[2];
  t_cmd		*pipe_list;

  cmd->entire_cmd = my_strreplace(cmd->entire_cmd, "grep", "grep -a");
  if (nb == 0)
    pipe_list = prep_pipe(cmd);
  else
    pipe_list = cmd;
  if (pipe(pipefd) == -1)
    {
      print_error(pipe_list->name);
      exit(1);
    }
  if ((pid = fork()) == -1)
    {
      print_error(pipe_list->name);
      exit(1);
    }
  if (pid == 0)
    exec_child_process(pipe_list, path, env, pipefd);
  else
    exec_parent_process(pipe_list, path, env, pipefd);
}

int		prep_exec_pipe(t_cmd *cmd, char **path, char **env)
{
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    return (0);
  if (pid == 0)
    exec_pipe(cmd, path, env, 0);
  else
    wait(&status);
  return (status);
}
