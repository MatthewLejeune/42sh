/*
** exec_operator.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon May 11 15:53:05 2015 Matthew LEJEUNE
** Last update Mon May 18 16:00:38 2015 Nathan Roy
*/

#include "42sh.h"

void		change_cmd_operator()
{
}

void		exec_operator_and(t_cmd *cmd, char **path, char **env)
{
  int		status;
  char		**cmd_split;
  char		**params;
  t_cmd		*new_cmd;

  new_cmd = NULL;
  path = path;
  cmd->entire_cmd = my_strreplace(cmd->entire_cmd, "&&", "$");
  cmd_split = my_split(cmd->entire_cmd, '$');
  cmd_split = epur_str_tab(cmd_split);
  params = my_split(cmd_split[0], ' ');
  add_cmd(&new_cmd, params[0], params, cmd_split[0]);
  status = exec_cmd(new_cmd, env);
  params = my_split(cmd_split[1], ' ');
  add_cmd(&new_cmd, params[0], params, cmd_split[1]);
  if (status == 0 && new_cmd->next != NULL)
    exec_cmd(new_cmd->next, env);
}

void		exec_operator_or(t_cmd *cmd, char **path, char **env)
{
  int		status;
  char		**cmd_split;
  char		**params;
  t_cmd		*new_cmd;

  new_cmd = NULL;
  path = path;
  cmd->entire_cmd = my_strreplace(cmd->entire_cmd, "||", "$");
  cmd_split = my_split(cmd->entire_cmd, '$');
  cmd_split = epur_str_tab(cmd_split);
  params = my_split(cmd_split[0], ' ');
  add_cmd(&new_cmd, params[0], params, cmd_split[0]);
  status = exec_cmd(new_cmd, env);
  params = my_split(cmd_split[1], ' ');
  add_cmd(&new_cmd, params[0], params, cmd_split[1]);
  if (status != 0 && new_cmd->next != NULL)
    exec_cmd(new_cmd->next, env);
}
