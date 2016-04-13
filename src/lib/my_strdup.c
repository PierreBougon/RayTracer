/*
** my_strdup.c<lib> for LIB in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:28:13 2016 romain samuel
** Last update Sun Apr 10 14:17:27 2016 romain samuel
*/

#include <lapin.h>
#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*cpy;

  if (str == NULL)
    return (NULL);
  i = 0;
  if ((cpy = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = 0;
  return (cpy);
}
