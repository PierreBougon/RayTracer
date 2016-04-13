/*
** my_strlen.c<lib> for LIB in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:28:45 2016 romain samuel
** Last update Tue Apr  5 15:28:54 2016 romain samuel
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
