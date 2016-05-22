/*
** my_bzero.c for bzero in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 12:38:26 2016 bougon_p
** Last update Mon Mar 28 12:44:51 2016 bougon_p
*/

#include "my.h"

void		*my_bzero(void *b, size_t len)
{
  size_t	counter;
  char		*str;

  str = (char *)b;
  if (!str)
    return (NULL);
  if (len == 0)
    return (str);
  counter = 0;
  while (counter < len)
    {
      str[counter] = 0;
      counter++;
    }
  return (b);
}
