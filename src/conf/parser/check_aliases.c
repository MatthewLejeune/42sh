/*
** check_aliases.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 26 18:24:24 2015 Matthew LEJEUNE
** Last update Sun May 24 18:30:01 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		is_alias(char *line)
{
  if (my_strncmp(line, "alias", 5) == 0)
    return (0);
  return (-1);
}

int		check_alias(char *line, int cur_case)
{
  int		pos;
  char		*str;

  pos = -1;
  if (my_strncmp(line, "alias", 5) != 0)
    return (-1);
  if ((pos = get_index_of(line, '=')) == -1)
    {
      printf("42shrc : missing '=' statement at line %d\n", cur_case + 1);
      return (-1);
    }
  if (get_nindex_of(line, '\'', 1) == -1 || get_nindex_of(line, '\'', 2) == -1)
    {
      printf("42shrc : missing '\'' statement at line %d\n", cur_case + 1);
      return (-1);
    }
  str = my_substr(line, get_index_of(line, ' '), pos);
  if (my_strlen(str) <= 0)
    {
      printf("42shrc : missing alias name at line %d\n", cur_case + 1);
      return (-1);
    }
  free(str);
  return (0);
}

char		**get_alias(char *line)
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  tab[0] = my_substr(line, get_index_of(line, ' '), get_index_of(line, '='));
  tab[1] = my_substr(line, get_nindex_of(line, '\'', 1),
		     get_nindex_of(line, '\'', 2));
  tab[2] = NULL;
  return (tab);
}
