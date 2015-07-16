/*
** get_conf_file.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sat Apr 25 16:20:25 2015 Matthew LEJEUNE
** Last update Sat May 30 12:36:54 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void		*print_error2()
{
  fprintf(stderr, RED"No configuration file found..\n"RESET);
  return (NULL);
}

char		**get_conf_file()
{
  int		cur_case;
  int		fd;
  char		*str;
  char		**file_content;

  cur_case = -1;
  file_content = NULL;
  if ((file_content = my_realloc_double(file_content, 1)) == NULL)
    return (NULL);
  if ((fd = open(".42shrc", O_RDONLY)) == -1)
    return (print_error2());
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((file_content = my_realloc_double(file_content, 1)) == NULL)
	{
	  free_tab(file_content);
	  return (NULL);
	}
      file_content[++cur_case] = my_strdup(str);
      free(str);
    }
  file_content[++cur_case] = NULL;
  close(fd);
  return (file_content);
}
