/*
** 42sh.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 19 17:34:51 2015 Matthew LEJEUNE
** Last update Sat May 30 15:48:24 2015 Matthew LEJEUNE
*/

#include "42sh.h"

t_cmd		*parse_cmd(char *cmd)
{
  int		cur_case;
  t_cmd		*cmds;
  char		**tab_cmds;
  char		**split_cmd;

  cmds = NULL;
  cur_case = -1;
  if ((tab_cmds = my_split(cmd, ';')) == NULL)
    return (NULL);
  tab_cmds = epur_str_tab(tab_cmds);
  while (tab_cmds[++cur_case])
    if (tab_cmds[cur_case][0] != '\0')
      {
	split_cmd = my_split(tab_cmds[cur_case], ' ');
	add_cmd(&cmds, my_strdup(split_cmd[0]),
		array_cpy(split_cmd), my_strdup(tab_cmds[cur_case]));
	free_tab(split_cmd);
      }
  free_tab(tab_cmds);
  return (cmds);
}

void		exec_before(t_cmd *cmd, int pipefd[2], char **env)
{
  t_cmd		*temp;

  temp = cmd;
  while (temp != NULL)
    {
      dup2(pipefd[0], 0);
      dup2(pipefd[1], 1);
      if (temp->name != NULL)
	exec_cmd(temp, env);
      temp = temp->next;
    }
  close(pipefd[1]);
  close(pipefd[0]);
  free_cmd_list(cmd);
}

char		*prompt_2(char **env, char *cmd, t_cmd *cmds)
{
  int	pipefd[2];

  pipe(pipefd);
  if (cmd[0] != '\0' && cmd[0] != ' ')
    {
      dup2(0, pipefd[0]);
      dup2(1, pipefd[1]);
      cmd = epur_str(cmd);
      cmds = parse_cmd(cmd);
      if (get_index_of(cmd, '$') != -1 || get_index_of(cmd, '=') != -1)
	env = variable(cmds, env);
      exec_before(cmds, pipefd, env);
    }
  return (cmd);
}

int		prompt(char **env, int *done)
{
  char		*cmd;

  my_putstr("$> ");
  if ((cmd = get_cmd(0)) != NULL)
    {
      cmd = prompt_2(env, cmd, NULL);
      free(cmd);
    }
  else
    *done = 1;
  return (0);
}

int		main(int argc, char *argv[], char **env)
{
  int		done;
  char		**env_cpy;

  done = 0;
  argc = argc;
  argv = argv;
  env_cpy = NULL;
  if ((env_cpy = array_cpy(env)) == NULL)
    return (-1);
  if (isatty(0))
    sig_def_shell();
  add_aliases();
  while (done == 0)
    {
      env_cpy = my_realloc_double(env_cpy, 1);
      prompt(env_cpy, &done);
    }
  if (env_cpy)
    free_tab(env_cpy);
  my_putstr("exit\n");
  return (0);
}

