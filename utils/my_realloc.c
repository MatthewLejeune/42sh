/*
** my_realloc.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:22:35 2015 Matthew LEJEUNE
** Last update Sat May 30 10:56:53 2015 Nathan Roy
*/

#include "42sh.h"

char		*my_realloc(char *str, int size)
{
  int		cur_char;
  char		*new_str;

  cur_char = 0;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + size + 1))) == NULL)
    return (NULL);
  new_str = my_memset(new_str, '\0', (my_strlen(str) + size + 1));
  if (str)
    {
      while (str[cur_char])
	{
	  new_str[cur_char] = str[cur_char];
	  cur_char++;
	}
      free(str);
    }
  return (new_str);
}

char		**my_realloc_double(char **tab, int size)
{
  int		cur_case;
  char		**new_tab;

  cur_case = -1;
  if ((new_tab = malloc(sizeof(char *) *
			(get_nb_elem(tab) + size + 1))) == NULL)
    return (NULL);
  new_tab = my_memset_double(new_tab, NULL, (get_nb_elem(tab) + size + 1));
  if (tab != NULL)
    {
      while (tab[++cur_case])
	new_tab[cur_case] = my_strdup(tab[cur_case]);
      free_tab(tab);
    }
  return (new_tab);
}
