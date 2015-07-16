/*
** get_nb_elem.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Mon Apr 20 08:16:29 2015 Matthew LEJEUNE
** Last update Mon Apr 20 08:17:33 2015 Matthew LEJEUNE
*/

int		get_nb_elem(char **array)
{
  int		cur_case;

  cur_case = 0;
  if (array)
    while (array[cur_case])
      cur_case++;
  return (cur_case);
}
