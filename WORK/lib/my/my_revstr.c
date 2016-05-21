/*
** my_revstr.c for my_revstr in /home/brout_m/dev/piscine/PJ6
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Oct  5 13:49:10 2015 marc brout
** Last update Mon Mar 14 11:34:20 2016 marc brout
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	end;
  char	stock;

  i = 0;
  end = my_strlen(str) - 1;
  while (i < (my_strlen(str) / 2))
    {
      stock = str[i];
      str[i] = str[end];
      str[end] = stock;
      i = i + 1;
      end = end - 1;
    }
  return (str);
}
