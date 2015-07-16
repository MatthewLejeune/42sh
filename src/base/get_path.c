/*
** get_path.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 09:32:22 2015 Matthew LEJEUNE
** Last update Thu May 28 17:47:32 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		**get_path(char **env)
{
  int		found;
  int		cur_case;
  char		*path;
  char		**tab_path;

  cur_case = -1;
  found = 0;
  while (found == 0 && env[++cur_case] != NULL)
    if (my_strncmp("PATH=", env[cur_case], 5) == 0)
      found = 1;
  if (found == 0)
    return (NULL);
  path = my_substr(env[cur_case], 4, my_strlen(env[cur_case]));
  tab_path = my_split(path, ':');
  free(path);
  return (tab_path);
}
