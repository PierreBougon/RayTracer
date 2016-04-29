/*
** put_base.c for base in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 22:11:09 2016 bougon_p
** Last update Fri Apr 29 22:44:04 2016 bougon_p
*/

#include "raytracer.h"

static  char    *cleanstr(char *nbr)
{
  char          *clean;
  int           p;
  int           i;

  if ((clean = bunny_malloc(sizeof(char) * 11 + 3)) == NULL)
    return (NULL);
  clean = my_bzero(clean, 11 + 3);
  p = 0;
  while (nbr[p++] == 0 && p < 10);
  if (p == 10)
    {
      clean[0] = '0';
      clean[1] = 0;
      bunny_free(nbr);
      return (clean);
    }
  clean[0] = '0';
  clean[1] = 'x';
  i = 2;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  bunny_free(nbr);
  return (clean);
}

char		*put_base(unsigned int	nbr, char *base)
{
  unsigned int	base_len;
  int		i;
  char		*num;

  base_len = my_strlen(base);
  if ((num = bunny_malloc(sizeof(char) * 11)) == NULL)
    return (NULL);
  my_bzero(num, 11);
  i = 9;
  while (nbr / base_len >= 0)
    {
      num[i--] = base[nbr % base_len];
      nbr /= base_len;
      if (nbr == 0)
	break ;
    }
  return (cleanstr(num));
}
