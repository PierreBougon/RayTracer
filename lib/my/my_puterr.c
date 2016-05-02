/*
** my_puterr.c<lib> for LIB in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:26:35 2016 romain samuel
** Last update Thu Apr 28 14:20:23 2016 bougon_p
*/

#include <unistd.h>
#include "my.h"

int	my_puterr(char *str)
{
  if (write(2, "Error: raytracer2: ",
	    my_strlen("Error: raytracer2: ")) == -1)
    return (1);
  if (write(2, str, my_strlen(str)) == -1)
    return (1);
  if (write(2, "\n", 1) == -1)
    return (1);
  return (-1);
}

void	*my_puterror(char *str)
{
  if (write(2, "Error: raytracer2: ",
	    my_strlen("Error: raytracer2: ")) == -1)
    return (NULL);
  if (write(2, str, my_strlen(str)) == -1)
    return (NULL);
  if (write(2, "\n", 1) == -1)
    return (NULL);
  return (NULL);
}
