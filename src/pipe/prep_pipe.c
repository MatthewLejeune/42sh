/*
** prep_pipe.c for prep_pipe.c in /home/roy_n/PSU_2014_42sh/src/pipe
** 
** Made by Nathan Roy
** Login   <roy_n@epitech.net>
** 
** Started on  Sat May 23 18:55:38 2015 Nathan Roy
** Last update Sat May 23 18:55:52 2015 Nathan Roy
*/

#include "42sh.h"

t_cmd           *prep_pipe(t_cmd *cmd)
{
  int           cur_case;
  char          **pipe_tab;
  char          **split_pipe;
  t_cmd         *pipe_lst;

  cur_case = -1;
  pipe_lst = NULL;
  pipe_tab = my_split(cmd->entire_cmd, '|');
  pipe_tab = epur_str_tab(pipe_tab);
  while (pipe_tab[++cur_case])
    {
      split_pipe = my_split(pipe_tab[cur_case], ' ');
      add_cmd(&pipe_lst, my_strdup(split_pipe[0]),
              array_cpy(split_pipe), my_strdup(pipe_tab[cur_case]));
      free_tab(split_pipe);
    }
  free_tab(pipe_tab);
  return (pipe_lst);
}
