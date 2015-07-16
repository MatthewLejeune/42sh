/*
** my_split.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:21:58 2015 Matthew LEJEUNE
** Last update Sun May 24 13:14:10 2015 Nathan Roy
*/

#include "42sh.h"

int		get_nb_elem_split(char *str, char c)
{
  int		cur_char;
  int		nb;

  cur_char = -1;
  nb = 0;
  while (str[++cur_char])
    if (str[cur_char] == c)
      nb++;
  return (nb + 1);
}

char		*char_concat(char *str, char c)
{
  int		cur_char;
  char		*new_str;

  cur_char = -1;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[++cur_char])
    new_str[cur_char] = str[cur_char];
  new_str[cur_char] = c;
  new_str[++cur_char] = '\0';
  free(str);
  return (new_str);
}

char		**my_split(char *str, char s)
{
  int		cur_case;
  int		cur_char;
  char		**t;

  cur_char = -1;
  cur_case = 0;
  if ((t = malloc(sizeof(char *) * (get_nb_elem_split(str, s) + 2))) == NULL ||
      (t[0] = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  t[0][0] = '\0';
  while (str[++cur_char])
      if (str[cur_char] == s)
	{
	  if ((t[++cur_case] = malloc(sizeof(char) * 1)) == NULL)
	    return (NULL);
	  t[cur_case][0] = '\0';
	}
      else
	{
	  if ((t[cur_case] = my_realloc(t[cur_case], 1)) == NULL)
	    return (NULL);
	  t[cur_case] = char_concat(t[cur_case], str[cur_char]);
	}
  t[++cur_case] = NULL;
  return (t);
}
