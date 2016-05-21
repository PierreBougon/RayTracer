/*
** my_alpha_num.c for ALPHA-NUM in /home/bougon_p/rendu/PSU_2015_minishell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr  7 20:25:10 2016 bougon_p
** Last update Wed Apr 13 21:20:15 2016 bougon_p
*/

#include "my.h"

bool	is_alpha_num(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if ((str[i] > '9' || str[i] < '0')
	  && (str[i] > 'z' || str[i] < 'a')
	  && (str[i] > 'Z' || str[i] < 'A'))
	return (false);
    }
  return (true);
}

bool	is_alpha(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if ((str[i] > 'z' || str[i] < 'a')
	  && (str[i] > 'Z' || str[i] < 'A'))
	return (false);
    }
  return (true);
}

bool	is_num(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if ((str[i] > '9' || str[i] < '0'))
	return (false);
    }
  return (true);
}
