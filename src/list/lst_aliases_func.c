/*
** lst_aliases_func.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat Apr 25 16:03:15 2015 Matthew LEJEUNE
** Last update Sun May 24 23:07:50 2015 Matthew LEJEUNE
*/

#include "42sh.h"

t_aliases	*get_list_alias(int flag, t_aliases *new_aliases)
{
  static t_aliases	*lst_aliases = NULL;

  if (flag == GET)
    return (lst_aliases);
  else if (flag == SET)
    lst_aliases = new_aliases;
  return (NULL);
}

t_aliases	*new_alias(char *name, char *cmd)
{
  t_aliases	*new_alias;

  if ((new_alias = malloc(sizeof(t_aliases))) == NULL)
    return (NULL);
  new_alias->name = name;
  new_alias->cmd = cmd;
  new_alias->checked = 0;
  new_alias->next = NULL;
  new_alias->prev = NULL;
  return (new_alias);
}

int		add_new_alias(t_aliases **aliases, char *name, char *cmd)
{
  t_aliases	*new_als;
  t_aliases	*last_alias;

  if ((new_als = new_alias(name, cmd)) == NULL)
    return (-1);
  if (*aliases == NULL)
    *aliases = new_als;
  else
    {
      last_alias = *aliases;
      while (last_alias->next != NULL)
	last_alias = last_alias->next;
      last_alias->next = new_als;
      new_als->prev = last_alias;
    }
  return (0);
}

int		display_alias_list(t_aliases *aliases)
{
  t_aliases	*display;

  display = aliases;
  while (display != NULL)
    {
      printf("Alias : %s\nChecked : %d\nCmd : %s\n", display->name,
	     display->checked, display->cmd);
      display = display->next;
    }
  return (0);
}

void		free_alias(t_aliases *aliases)
{
  t_aliases	*free_struct;
  t_aliases	*temp;

  free_struct = aliases;
  while (free_struct != NULL)
    {
      temp = free_struct;
      free_struct = free_struct->next;
      free(temp);
    }
  aliases = NULL;
}
