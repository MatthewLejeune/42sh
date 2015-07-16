/*
** use_alias.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 28 08:52:25 2015 Matthew LEJEUNE
** Last update Sun May 24 17:53:04 2015 Nathan Roy
*/

#include "42sh.h"

void		reset_checked(t_aliases *cmd)
{
  t_aliases	*temp;

  temp = cmd;
  while (temp != NULL)
    {
      temp->checked = 0;
      temp = temp->next;
    }
  get_list_alias(SET, cmd);
}

t_cmd		*get_entire_cmd(t_cmd *cmd)
{
  t_aliases	*alias;
  t_aliases	*temp;
  char		**tab_cmd;

  alias = get_list_alias(GET, NULL);
  temp = alias;
  while (temp != NULL)
    {
      if (temp->checked == 0)
	if (my_strncmp(cmd->name, temp->name,
		       get_longest_string(cmd->name, temp->name)) == 0)
	  {
	    cmd->entire_cmd = my_strreplace(cmd->entire_cmd, cmd->name, temp->cmd);
	    tab_cmd = my_split(cmd->entire_cmd, ' ');
	    cmd->name = tab_cmd[0];
	    cmd->params = tab_cmd;
	    temp->checked = 1;
	    get_list_alias(SET, alias);
	    return (get_entire_cmd(cmd));
	  }
      temp = temp->next;
    }
  reset_checked(alias);
  return (cmd);
}
