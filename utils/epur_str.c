/*
** epur_str.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Thu Apr 30 15:13:47 2015 Matthew LEJEUNE
** Last update Sat May 30 11:23:35 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char		*epur_str(char *str)
{
  int		i;
  char		*str2;
  int		p;

  p = -1;
  i = -1;
  if ((str2 = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[++i] == ' ' || str[i] == '\t');
  while (str[i] != 0)
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[++i] == ' ' || str[i] == '\t');
	  if (str[i] != 0)
	    str2[++p] = ' ';
	}
      else
	  str2[++p] = str[i++];
    }
  str2[++p] = 0;
  free(str);
  return (str2);
}

char		*supress_spaces(char *str)
{
  int		cur_char;
  int		cur_char_new;
  char		*new_str;

  cur_char = -1;
  cur_char_new = -1;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  if (str)
    {
      while (str[++cur_char])
	if (str[cur_char] != ' ')
	  new_str[++cur_char_new] = str[cur_char];
      free(str);
    }
  new_str[++cur_char_new] = '\0';
  return (new_str);
}
