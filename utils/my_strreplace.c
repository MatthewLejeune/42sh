/*
** my_strreplace.c for 42sh in /home/lejeun_m/42sh/test
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Apr 28 11:22:51 2015 Matthew LEJEUNE
** Last update Sun May 24 13:17:19 2015 Nathan Roy
*/

#include "42sh.h"

char		*insert_replace(char *str, char *replace, char *str_replace,
				char *new_str)
{
  int		cur_char_replace;
  int		cur_char;
  int		cur_char_str;
  int		found;

  cur_char = -1;
  cur_char_str = -1;
  found = 0;
  cur_char_replace = -1;
  while (str[++cur_char])
    if (my_strncmp(&str[cur_char], replace, my_strlen(replace))
	== 0 && found == 0)
      {
	while (str_replace[++cur_char_replace])
	  new_str[++cur_char_str] = str_replace[cur_char_replace];
	cur_char += my_strlen(replace) - 1;
	found = 1;
      }
    else
      new_str[++cur_char_str] = str[cur_char];
  return (new_str);
}

char		*my_strreplace(char *str, char *replace, char *str_replace)
{
  char		*new_str;

  if ((new_str = malloc(sizeof(char) *
			(my_strlen(str) - my_strlen(replace)
			 + my_strlen(str_replace) + 1))) == NULL)
    return (NULL);
  new_str = my_memset(new_str, '\0', (my_strlen(str) - my_strlen(replace)
				      + my_strlen(str_replace) + 1));
  new_str = insert_replace(str, replace, str_replace, new_str);
  return (new_str);
}
