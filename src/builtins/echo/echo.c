/*
** echo.c for echo.c in /home/roy_n/PSU_2014_42sh/src/builtins/echo
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Thu May 21 11:29:37 2015 Nathan Roy
** Last update Sun May 24 22:59:10 2015 Matthew LEJEUNE
*/

#include "42sh.h"

void	my_putecho(int flag, char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\\' && flag == 0)
	i++;
      else
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
}

int	echo(t_cmd *cmd, char ***env)
{
  int	flag_n;
  int	i;

  i = 1;
  env = env;
  flag_n = 0;
  if (cmd->params[1] != NULL && my_strcmp(cmd->params[1], "-n") == 0)
    {
      i++;
      flag_n = 1;
    }
  while (cmd->params[i] != NULL)
    {
      my_putecho(0, cmd->params[i]);
      i++;
      if ( cmd->params[i] != NULL)
     	my_putchar(' ');
    }
  if (flag_n == 0)
    my_putchar('\n');
  return (0);
}
