/*
** my_puterr.c<lib> for LIB in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:26:35 2016 romain samuel
** Last update Tue Apr  5 15:27:12 2016 romain samuel
*/

#include <unistd.h>
#include "my.h"

int	my_puterr(char *str)
{
  write(2, "Error: raytracer2: ", my_strlen("Error: raytracer2: "));
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (-1);
}

void	*my_puterror(char *str)
{
  write(2, "Error: raytracer2: ", my_strlen("Error: raytracer2: "));
  write(2, str, my_strlen(str));
  write(2, "\n", 1);
  return (NULL);
}
