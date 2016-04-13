/*
** my_getcolor.c<lib> for LIB in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:25:15 2016 romain samuel
** Last update Tue Apr  5 15:25:58 2016 romain samuel
*/

#include "my.h"

int	my_string_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	check_base(char *base)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (base[i] != '\0')
    {
      while (base[j] != '\0')
	{
	  if (i != j && base[i] == base[j])
	    return (-1);
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (0);
}

unsigned int	my_getnbr_base(char *str, char *base)
{
  unsigned int	nb;
  unsigned int	size_base;
  unsigned int	i;
  unsigned int	j;

  size_base = my_string_len(base);
  nb = 0;
  i = 0;
  if (check_base(base) == -1)
    return (0);
  while (str[i] != '\0')
    {
      j = 0;
      while (j < size_base && base[j] != str[i])
	j = j + 1;
      if (base[j] == str[i])
	nb = nb * size_base + j;
      else
	if ((str[i] != '-' && str[i] != '+'))
	  return (0);
      i = i + 1;
    }
  return (nb);
}

unsigned int	my_getcolor(char *str, char *base)
{
  unsigned int	ret;

  if (str[0] != '0' || str[1] != 'x')
    return (0);
  if (my_string_len(str) == 10)
    return (my_getnbr_base(&str[2], base));
  else if (my_string_len(str) == 8)
    {
      if ((ret = my_getnbr_base(&str[2], base)) == 0)
	return (0);
      return (0xFF000000 + ret);
    }
  else
    return (0);
}
