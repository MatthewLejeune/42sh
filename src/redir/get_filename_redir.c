/*
** get_filename_redir.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Thu Apr 30 14:40:53 2015 Matthew LEJEUNE
** Last update Sat May 30 11:38:05 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*get_filename(char *cmd)
{
  int		cur_case;
  char		**tab;
  char		*name;

  cur_case = -1;
  if (!cmd)
    return (NULL);
  tab = my_split(cmd, ' ');
  if ((cur_case = get_index_elem(tab, ">")) == -1 &&
      (cur_case = get_index_elem(tab, ">>")) == -1 &&
      (cur_case = get_index_elem(tab, "<")) == -1)
        return (NULL);
  name = my_strdup(tab[cur_case + 1]);
  free_tab(tab);
  return (name);
}
