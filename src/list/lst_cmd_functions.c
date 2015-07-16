/*
** lst_cmd_functions.c for 42sh in /home/lejeun_m/42sh/src/list
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Fri Apr 17 10:37:26 2015 Matthew LEJEUNE
** Last update Sat May 30 11:32:37 2015 Matthew LEJEUNE
*/

#include "42sh.h"

t_cmd		*create_new_cmd(char *name, char **args, char *entire_cmd)
{
  t_cmd		*new_cmd;

  if ((new_cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  new_cmd->name = name;
  new_cmd->params = args;
  new_cmd->entire_cmd = entire_cmd;
  new_cmd->next = NULL;
  new_cmd->prev = NULL;
  return (new_cmd);
}

int		add_cmd(t_cmd **cmds, char *name, char **args, char *entire_cmd)
{
  t_cmd		*new_cmd;
  t_cmd		*last_cmd;

  if ((new_cmd = create_new_cmd(name, args, entire_cmd)) == NULL)
    return (-1);
  if (*cmds == NULL)
    *cmds = new_cmd;
  else
    {
      last_cmd = *cmds;
      while (last_cmd->next != NULL)
	last_cmd = last_cmd->next;
      last_cmd->next = new_cmd;
      new_cmd->prev = last_cmd;
    }
  return (0);
}

void		show_cmd_list(t_cmd *cmds)
{
  t_cmd		*display;
  int		cur_case;

  display = cmds;
  cur_case = -1;
  while (display != NULL)
    {
      printf("Commande : %s\n", display->name);
      printf("\tParams :\n");
      while (display->params[++cur_case])
	     printf("\t\t%s,\n", display->params[cur_case]);
      display = display->next;
    }
}

void		free_cmd_list(t_cmd *cmds)
{
  t_cmd		*free_struct;
  t_cmd		*temp;

  free_struct = cmds;
  while (free_struct != NULL)
    {
      temp = free_struct;
      free_struct = free_struct->next;
      free(temp->name);
      if (temp->params)
	free_tab(temp->params);
      free(temp->entire_cmd);
      free(temp);
    }
  cmds = NULL;
}
