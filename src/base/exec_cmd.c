/*
** exec_cmd.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Sun Apr 19 17:40:15 2015 Matthew LEJEUNE
** Last update Sat May 30 15:31:27 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		exec(t_cmd *cmd, char *full_path_cmd, char **env, int fd)
{
  pid_t		pid;
  int		exec;
  char		*file;

  if (is_redirection(cmd->entire_cmd) != -1)
    if ((file = get_filename(cmd->entire_cmd)) != NULL)
      get_fd(cmd, file, &fd);
  if (check_builtins(cmd, env) == -1)
    {
      if ((pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  sig_def_exec();
	  if (execve(full_path_cmd, cmd->params, env) == -1)
	    print_error(cmd->name);
	  exit(-1);
	}
      else
	if (wait(&exec) && exec == 139)
	  printf("Segmentation fault\n");
    }
  if (fd != -1)
    close(fd);
  return (exec);
}

char		*get_cmd_string(t_cmd *cmd, char **path, int cur_case)
{
  char		*full_path_cmd;
  char		*temp;

  full_path_cmd = cmd->params[0];
  if (cmd->entire_cmd[0] != '/' && cmd->entire_cmd[0] != '.')
    {
      temp = my_strcat(path[cur_case], "/");
      full_path_cmd = my_strcat(temp, cmd->name);
      free(temp);
    }
  else
    {
      if (cmd->entire_cmd[0] == '.')
	full_path_cmd = my_substr(cmd->entire_cmd, 1, my_strlen(cmd->entire_cmd));
      else if (cmd->entire_cmd[0] == '/')
	full_path_cmd = cmd->name;
    }
  return (full_path_cmd);
}

int		prep_exec(t_cmd *cmd, char **path, char **env)
{
  char		*full_path_cmd;
  int		cur_case;
  int		found;
  int		error;

  error = 1;
  cur_case = -1;
  found = 0;
  while (path != NULL && path[++cur_case] && found == 0)
    {
      full_path_cmd = get_cmd_string(cmd, path, cur_case);
      if (access(full_path_cmd, F_OK) != -1)
	{
	  error = exec(cmd, full_path_cmd, env, 0);
	  found = 1;
	}
      if (full_path_cmd[0] != '/')
	free(full_path_cmd);
    }
  if (path == NULL)
    error = exec(cmd, cmd->name, env, 0);
  else if (found == 0)
    error = exec(cmd, "\0", env, 0);
  return (error);
}

int		exec_cmd2(t_cmd *cmds, char **env, char **path)
{
  int		error;

  error = 0;
  if (my_strcmp(cmds->name, "exit") == 0)
    my_exit(cmds, NULL);
  error = prep_exec(cmds, path, env);
  return (error);
}

int		exec_cmd(t_cmd *cmds, char **env)
{
  char		**path;
  int		pipefd[2];
  int		error;

  pipe(pipefd);
  dup2(0, pipefd[0]);
  dup2(1, pipefd[1]);
  error = 0;
  path = get_path(env);
  if (is_pipe(cmds) == -1)
    get_entire_cmd(cmds);
  if (is_operator(cmds) == 1)
    exec_operator_and(cmds, path, env);
  else if (is_operator(cmds) == 2)
    exec_operator_or(cmds, path, env);
  else if (check_double_left_redir(cmds) != -1)
    prep_double_left_redir(cmds, path, env);
  else if (is_pipe(cmds) != -1)
    error = prep_exec_pipe(cmds, path, env);
  else
    error = exec_cmd2(cmds, env, path);
  if (path)
    free_tab(path);
  change_dup(pipefd);
  return (error);
}
