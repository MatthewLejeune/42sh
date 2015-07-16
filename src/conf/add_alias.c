/*
** add_alias.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 27 11:48:33 2015 Matthew LEJEUNE
** Last update Sun May 24 18:47:32 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		add_aliases()
{
  int		cur_case;
  char		**tab_conf;
  t_aliases	*alias;
  char		**alias_cmd;

  cur_case = -1;
  alias = get_list_alias(GET, NULL);
  if ((tab_conf = get_conf_file()) == NULL)
    return (0);
  while (tab_conf[++cur_case])
    {
      if (is_alias(tab_conf[cur_case]) != -1)
	if (check_alias(tab_conf[cur_case], cur_case) != -1)
	  {
	    if ((alias_cmd = get_alias(tab_conf[cur_case])) != NULL)
	      {
		add_new_alias(&alias, my_strdup(alias_cmd[0]),
			      my_strdup(alias_cmd[1]));
		free_tab(alias_cmd);
	      }
	  }
    }
  get_list_alias(SET, alias);
  free_tab(tab_conf);
  return (0);
}
