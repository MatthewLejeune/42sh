/*
** check_builtins.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 21 09:03:13 2015 Matthew LEJEUNE
** Last update Sun May 24 22:55:02 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*get_builtins()
{
  char		*builtins;

  builtins = "cd;exit;setenv;unsetenv;env;echo";
  return (builtins);
}

int		check_builtins(t_cmd *cmds, char **env)
{
  int		cur_case;
  char		**builtins;
  int		found;
  int		(*fptr[6])(t_cmd *, char ***);

  found = -1;
  cur_case = -1;
  if ((builtins = my_split(get_builtins(), ';')) == NULL)
    return (-1);
  fill_func_ptr(fptr);
  if (cmds->name != NULL)
    {
      while (builtins[++cur_case])
	if (my_strncmp(builtins[cur_case], cmds->name,
		       get_longest_string(builtins[cur_case], cmds->name)) == 0)
	  {
	    fptr[cur_case](cmds, &env);
	    found = 1;
	  }
      free_tab(builtins);
    }
  return (found);
}
