/*
** my_strcat.c for cat in /home/bougon_p/rendu/PSU_2015_minisell2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 28 17:20:20 2016 bougon_p
** Last update Mon Mar 28 17:20:43 2016 bougon_p
*/

#include "my.h"

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   p;

  i = -1;
  p = -1;
  while (dest[++i] != 0);
  while (src[++p] != 0)
    dest[i++] = src[p];
  dest[i] = 0;
  return (dest);
}
