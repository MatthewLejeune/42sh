/*
** get_next_line.c for get_next_line.c in /home/stepha_b/synaptique-stepha_b/gnl
** 
** Made by Alexandre Stephan
** Login   <stepha_b@epitech.net>
** 
** Started on  Tue Feb 10 17:05:11 2015 Alexandre Stephan
** Last update Sun May 24 13:10:56 2015 Nathan Roy
*/

#include "42sh.h"

char            *get_next_line(const int fd)
{
  static int    last = 1;
  static int    rd = 0;
  static int    i = 0;
  static char   *res = NULL;
  static char   b[BUFFER_SIZE];

  if (b[my_strlen(b) - rd] == '\0')
    {
      if ((rd = read(fd, b, BUFFER_SIZE)) <= 0)
        return (res = (last-- && b[my_strlen(b) - rd - 1] != 10) ? res : NULL);
      b[rd] = '\0';
    }
  if ((res = (i == 0) ? malloc(sizeof(*res) * BUFFER_SIZE + 1) :
       my_realloc(res, sizeof(*res) * BUFFER_SIZE + 1)) == NULL)
    return (NULL);
  while (b[my_strlen(b) - rd] && b[my_strlen(b) - rd] != '\n')
    res[i++] = b[my_strlen(b) - rd--];
  res[i] = '\0';
  if (b[my_strlen(b) - rd] == '\n')
    {
      i = 0;
      rd--;
      return (res);
    }
  return (get_next_line(fd));
}
