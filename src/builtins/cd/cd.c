/*
** cd.c for 42sh in /home/lejeun_m/42sh
**
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
**
** Started on  Tue Apr 21 08:12:10 2015 Matthew LEJEUNE
** Last update Sun May 24 22:57:44 2015 Matthew LEJEUNE
*/

#include "42sh.h"

int		change_env(char *pwd, char *oldpwd, char ***env)
{
  t_cmd		*cmd;
  char		**tab;

  cmd = NULL;
  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (0);
  tab[0] = "\0";
  tab[1] = "PWD";
  tab[2] = oldpwd;
  add_cmd(&cmd, tab[1], tab, NULL);
  my_unsetenv(cmd, env);
  my_setenv(cmd, env);
  tab[1] = "OLDPWD";
  tab[2] = pwd;
  cmd->name = tab[1];
  cmd->params = tab;
  my_unsetenv(cmd, env);
  my_setenv(cmd, env);
  return (0);
}

int		cd_minus(char ***env)
{
  char		*pwd;
  char		*oldpwd;

  if ((pwd = get_env_var("PWD", *env)) == NULL)
    {
      printf("cd : « PWD » undefined\n");
      return (0);
    }
  if ((oldpwd = get_env_var("OLDPWD", *env)) == NULL)
    {
      printf("cd : « OLDPWD » undefined\n");
      return (0);
    }
  if (chdir(oldpwd) == -1)
    {
      print_error("cd");
      return (0);
    }
  change_env(pwd, oldpwd, env);
  return (0);
}

int		cd_home(char ***env)
{
  char		*pwd;
  char		*home;

  if ((pwd = get_env_var("PWD", *env)) == NULL)
    {
      printf("cd : « PWD » undefined\n");
      return (0);
    }
  if ((home = get_env_var("HOME", *env)) == NULL)
    {
      printf("cd : « HOME » undefined\n");
      return (0);
    }
  if (chdir(home) == -1)
    {
      print_error("cd");
      return (0);
    }
  change_env(pwd, home, env);
  return (0);
}

int		cd(t_cmd *cmds, char ***env)
{
  char		*pwd;
  char		cwd[1024];

  if (!cmds->params[1])
    cd_home(env);
  else
    {
      if (my_strncmp(cmds->params[1], "-",
		     get_longest_string(cmds->params[1], "-")) == 0)
	cd_minus(env);
      else
	{
	  pwd = get_env_var("PWD", *env);
	  if (chdir(cmds->params[1]) == -1)
	    print_error(cmds->name);
	  else
	    change_env(pwd, getcwd(cwd, sizeof(cwd)), env);
	  free(pwd);
	}
    }
  return (0);
}
