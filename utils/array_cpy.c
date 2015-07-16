/*
** array_cpy.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:06:15 2015 Matthew LEJEUNE
** Last update Sat May 30 10:27:00 2015 Nathan Roy
*/

#include "42sh.h"

char		**array_cpy(char **array)
{
  int		cur_case;
  int		cur_char;
  char		**cpy;

  cur_case = -1;
  if ((cpy = malloc(sizeof(char *) * (get_nb_elem(array) + 1))) == NULL)
    return (NULL);
  cpy = my_memset_double(cpy, NULL, get_nb_elem(array) + 1);
  if (array)
    while (array[++cur_case])
      {
	cur_char = -1;
	if ((cpy[cur_case] = malloc(sizeof(char) *
				    (my_strlen(array[cur_case]) + 1))) == NULL)
	  return (NULL);
	while (array[cur_case][++cur_char])
	  cpy[cur_case][cur_char] = array[cur_case][cur_char];
	cpy[cur_case][cur_char] = '\0';
      }
  return (cpy);
}
