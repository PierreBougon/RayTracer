/*
** setunsnbr.c for setnbr in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 21:34:24 2016 bougon_p
** Last update Fri Apr 29 21:57:55 2016 bougon_p
*/

#include "raytracer.h"

static	char    *set_line_null(char *str, int length)
{
  int		i;

  i = -1;
  while (++i < length)
    str[i] = 0;
  return (str);
}

static	char    *cleanstr(char *nbr)
{
  char		*clean;
  int		p;
  int		i;

  if ((clean = bunny_malloc(sizeof(char) * 11)) == NULL)
    return (NULL);
  clean = set_line_null(clean, 11);
  p = 0;
  while (nbr[p++] == '0' && p < 11);
  if (p == 11)
    {
      clean[0] = '0';
      clean[1] = 0;
      bunny_free(nbr);
      return (clean);
    }
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  bunny_free(nbr);
  return (clean);
}

char    *setunsnbr(unsigned int nbr)
{
  char  *numb;
  int   i;
  int   p;

  p = 9;
  if ((numb = bunny_malloc(sizeof(char) * 11)) == NULL)
    return (NULL);
  set_line_null(numb, 11);
  i = 0;
  while (p >= 0)
    numb[p--] = ((nbr / (int)(pow(10, i++)) % 10) + '0');
  return (cleanstr(numb));
}
