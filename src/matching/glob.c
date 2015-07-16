/*
** glob.c for glob.c in /home/roy_n/PSU_2014_42sh/src/matching
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Wed May 13 10:56:25 2015 Nathan Roy
** Last update Thu May 14 11:35:32 2015 Nathan Roy
*/

#include <glob.h>
#include "../../include/42sh.h"

int	match(char *str, char **env)
{
  glob_t globbuf;
  int	i;

  i = 0;
  globbuf.gl_offs = 0;
  glob(str, GLOB_DOOFFS, NULL, &globbuf);
  while (globbuf.gl_pathv[i] != NULL)
    printf("%s\n", globbuf.gl_pathv[i++]);
  printf("%d\n", globbuf.gl_pathc);
}

int	read_line(char **env)
{
  char *str;
  int	i;

  i = 0;
  str = malloc(sizeof(char) * 2);
  str[0] = 0;
  str[1] = 0;
  write(1, ">", 1);
  while (read(0, &str[i], 1) > 0)
    {
      i++;
      while (read(0, &str[i], 1) > 0 && str[i] != '\n')
	{
	  str = realloc(str, 2);
	  i++;
	}
      str[i] = 0;
      match(str, env);
      str = malloc(sizeof(char) * 2);
      str[0] = 0;
      str[1] = 0;
      i = 0;
      write(1, ">", 1);
    }
}

int	main(int ac, char **av, char **env)
{
  read_line(env);
  return (0);
}
