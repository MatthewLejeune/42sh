/*
** get_next_line.c for get_next_line in /home/roy_n/rendu/get_next_line
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Mon Nov 17 14:31:58 2014 Nathan Roy
** Last update Sat May 30 12:39:42 2015 Matthew LEJEUNE
*/

#include "42sh.h"

char	*malloc_sec(char *str)
{
  char	*str1;
  int	i;
  int	lol;
  int	p;

  p = 0;
  i = 0;
  if (BUFFER_SIZE == 2147483647)
    lol = BUFFER_SIZE - 1;
  else
    lol = BUFFER_SIZE;
  while (str[p] != 0)
    p++;
  if ((str1 = malloc(sizeof(char) * (p + lol + 1)))
      == NULL)
    return (NULL);
  str1 = my_memset(str1, '\0', (p + lol + 1));
  while (str[i] != 0)
    {
      str1[i] = str[i];
      i++;
    }
  str1[i] = 0;
  free(str);
  return (str1);
}

char	*get_line(const int fd, char *str, int x, char *str1)
{
  int	i;
  int	error;

  i = x;
  if ((str = malloc_sec(str)) == NULL)
    return (NULL);
  if ((error = read(fd, &str[x], BUFFER_SIZE)) <= 0 && str[0] == 0)
    return (NULL);
  if (error != BUFFER_SIZE)
    x++;
  x = x + error;
  str[x] = 0;
  while (i < x)
    {
      if (str[i] == '\0' || str[i] == '\n')
	return (str);
      i++;
    }
  str = get_line(fd, str, x, str1);
  return (str);
}

char	*get_next_line_1(char *str, int x, const int fd, char *str1)
{
  int	i;

  i = 0;
  if ((str = get_line(fd, str, x, str1)) == NULL)
    {
      str1[0] = 0;
      return (NULL);
    }
  x = -1;
  while (str[++x] != '\n' && str[x] != 0);
  if (str[++x] != 0)
    {
      while (str[x] != 0)
	{
	  str1[i++] = str[x];
	  x++;
	}
      str1[i] = 0;
    }
  return (str);
}

int	get_next_line_2(int x, char *str1)
{
  int i;

  i = 0;
  x = -1;
  while (str1[++x] != '\n' && str1[x] != 0);
  while (str1[x++] != 0)
    str1[i++] = str1[x];
  str1[i] = 0;
  return (-1);
}

char	*get_cmd(const int fd)
{
  char	*str;
  int	x;
  static char	str1[BUFFER_SIZE];

  str1[0] = '\0';
  if (BUFFER_SIZE <= 0)
    return (NULL);
  if ((str = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
    return (NULL);
  x = -1;
  while (str1[++x] != 0 && str1[x] != '\n')
    str[x] = str1[x];
  str[x] = 0;
  if (str1[x] != '\n')
    str = get_next_line_1(str, x, fd, str1);
  else
    x = get_next_line_2(x, str1);
  if (str == NULL)
    return (NULL);
  x = -1;
  while (str[++x] != '\n' && str[x] != 0);
  str[x] = 0;
  return (str);
}
