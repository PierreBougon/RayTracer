/*
** my_getnbr.c for LIB in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:23:54 2016 romain samuel
** Last update Tue Apr  5 15:26:10 2016 romain samuel
*/

#include "my.h"

int	get_sign(char *str)
{
  int	i;
  int	sign;

  i = 0;
  sign = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	{
	  sign = sign + 1;
	}
      i++;
    }
  if ((sign % 2) != 0)
    return (i);
  return (0);
}

int	get_starting_point(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    i = i + 1;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    i = i + 1;
  return (i);
}

int	my_str_compare(char *s1, char *s2)
{
  int	i;
  int	j;
  int	temp;

  i = 0;
  j = 0;
  while (s1[i] > '9' || s1[i] < '0')
    i = i + 1;
  temp = i;
  while (s1[temp] != '\0' && s1[temp] >= '0' && s1[temp] <= '9')
    {
      temp = temp + 1;
    }
  if (my_strlen(s2) == temp - i)
    {
      while (s1[i] != '\0' && s2[j] != '\0' &&
	     s1[i] > '0' && s2[i] < '9' &&
	     s1[i] == s2[j])
	{
	  i = i + 1;
	  j = j + 1;
	}
      return (s1[i] - s2[i]);
    }
  return ((temp - i) - my_strlen(s2));
}

int	my_catch_overflow(char *str)
{
  int	sign;

  sign = get_sign(str);
  if (sign == 0 && my_str_compare(str, "2147483647") > 0)
    return (-1);
  else if (sign > 0 && my_str_compare(str, "2147483648") > 0)
    return (-1);
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	rank;

  nb = 0;
  i = 0;
  rank = 1;
  if (my_catch_overflow(str) == -1)
    return (0);
  i = get_starting_point(str) - 1;
  while (i >= 0 && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb + (rank * (str[i] - 48));
      i = i - 1;
      rank = rank * 10;
    }
  if (get_sign(str) > 0)
    nb = -nb;
  return (nb);
}
