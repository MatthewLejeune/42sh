/*
** my_strlen.c for 42sh in /home/lejeun_m/42sh
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Sun Apr 19 17:58:26 2015 Matthew LEJEUNE
** Last update Sun Apr 19 17:59:12 2015 Matthew LEJEUNE
*/

int		my_strlen(char *str)
{
  int		cur_char;

  cur_char = 0;
  if (str)
    while (str[cur_char])
      cur_char++;
  return (cur_char);
}
