/*
** double_left_redir.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat May  2 19:10:52 2015 Matthew LEJEUNE
** Last update Sat May 30 15:51:08 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*get_str_stop(t_cmd *cmd)
{
  int		cur_case;

  cur_case = -1;
  while (cmd->params[++cur_case])
    if (my_strcmp(cmd->params[cur_case], "<<") == 0)
      return (cmd->params[cur_case + 1]);
  return (NULL);
}

void		change_cmd_left_redir(t_cmd *cmd)
{
  int		cur_char;
  char		*cmd_str;
  char		**split;

  cur_char = get_index_of(cmd->entire_cmd, '<');
  cmd_str = my_substr(cmd->entire_cmd, -1, cur_char);
  cmd_str = epur_str(cmd_str);
  cmd->entire_cmd = my_strdup(cmd_str);
  split = my_split(cmd->entire_cmd, ' ');
  cmd->name = my_strdup(split[0]);
  cmd->params = array_cpy(split);
  free_tab(split);
  free(cmd_str);
}

void		double_left_redir2(t_cmd *cmd, int *pipefd)
{
  char		*str;
  char		*str_stop;
  int		done;

  close(pipefd[0]);
  done = 0;
  while (done == 0)
    {
      my_putstr("> ");
      if ((str_stop = get_str_stop(cmd)) == NULL)
	{
	  close(pipefd[1]);
	  exit(EXIT_FAILURE);
	}
      if ((str = get_cmd(0)) == NULL)
	exit(EXIT_FAILURE);
      if (my_strcmp(str, str_stop) == 0)
	{
	  close(pipefd[1]);
	  done = 1;
	}
      write(pipefd[1], str, my_strlen(str));
      write(pipefd[1], "\n", 1);
    }
  exit(-1);
}

int		double_left_redir(t_cmd *cmd, char **path, char **env)
{
  int		pipefd[2];
  int		status;
  pid_t		pid;

  pipe(pipefd);
  path = path;
  if ((pid = fork()) == -1)
    return (0);
  if (pid == 0)
    double_left_redir2(cmd, pipefd);
  else
    {
      wait(&status);
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      change_cmd_left_redir(cmd);
      return (prep_exec(cmd, path, env));
    }
  return (0);
}

int		prep_double_left_redir(t_cmd *cmd, char **path, char **env)
{
  sig_def_exec();
  double_left_redir(cmd, path, env);
  return (0);
}
