/*
** lst_history_functions.c for 42sh in /home/lejeun_m/Projets/PSU_2014_42sh/src
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun May 24 16:30:08 2015 Matthew LEJEUNE
** Last update Sun May 24 23:08:18 2015 Matthew LEJEUNE
*/

#include "42sh.h"

t_history	create_new_entry(int index, char *cmd)
{
  t_history	*new_entry;

  if ((new_entry = malloc(sizeof(*new_entry))) == NULL)
    return (NULL);
  new_entry->index = index;
  new_entry->name = name;
  new_entry->next = NULL;
  new_entry->prev = NULL;
  return (new_entry);
}

int		add_new_entry(t_history **lst_history, char *cmd)
{
  t_history	*new_entry;
  t_history	*last_entry;

  if ((new_entry = create_new_entry(get_nb_elem_history(*lst_history),
				    cmd)) == NULL)
    return (-1);
  if (*lst_history == NULL)
    *lst_history = new_entry;
  else
    {
      last_entry = *lst_history;
      while (last_entry->next != NULL)
	last_entry = last_entry->next;
      last_entry->next = new_entry;
      new_entry->prev = last_entry;
    }
  return (0);
}

void		show_history_lst(t_history *lst_history)
{
  t_history	*display;

  display = lst_history;
  while (display != NULL)
    {
      printf(RED"%d "RESET"%s", display->index, display->name);
      display = display->next;
    }
}

int		get_nb_elem_history(t_history *lst_history)
{
  int		nb_elem;
  t_history	*count;

  nb_elem = 1:
  count = lst_history;
  while (count != NULL)
    {
      nb_elem++;
      count = count->next;
    }
  return (nb_elem);
}

void		free_lst_history(t_history *lst_history)
{
  t_history	*free_temp;
  t_history	*tmp;

  free_temp = lst_history;
  while (free_temp != NULL)
    {
      temp = free_temp;
      free_temp = free_temp->next;
      free(temp);
    }
  lst_history = NULL;
}
