/*
** save_ini_obj.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 00:46:59 2016 bougon_p
** Last update Fri Apr 29 01:19:48 2016 bougon_p
*/

#include "raytracer.h"

char	*sphere_name(UNUSED t_data *data, int nbr)
{
  char	*num;
  char	*name;

  num = setnbr(nbr);
  if ((name = malloc(sizeof(char) *
		     my_strlen("sphere") + my_strlen(num) + 1)) == NULL)
    return (NULL);
  my_bzero(name, my_strlen("sphere") + my_strlen(num) + 1);
  my_strcpy(name, "sphere");
  my_strcat(name, num);
  bunny_free(num);
  return (name);
}

char	*cylinder_name(UNUSED t_data *data, int nbr)
{
  char	*num;
  char	*name;

  num = setnbr(nbr);
  if ((name = malloc(sizeof(char) *
		     my_strlen("cylinder") + my_strlen(num) + 1)) == NULL)
    return (NULL);
  my_bzero(name, my_strlen("cylinder") + my_strlen(num) + 1);
  my_strcpy(name, "cylinder");
  my_strcat(name, num);
  bunny_free(num);
  return (name);
}

char	*cone_name(UNUSED t_data *data, int nbr)
{
  char	*num;
  char	*name;

  num = setnbr(nbr);
  if ((name = malloc(sizeof(char) *
		     my_strlen("cone") + my_strlen(num) + 1)) == NULL)
    return (NULL);
  my_bzero(name, my_strlen("cone") + my_strlen(num) + 1);
  my_strcpy(name, "cone");
  my_strcat(name, num);
  bunny_free(num);
  return (name);
}

char	*plane_name(UNUSED t_data *data, int nbr)
{
  char	*num;
  char	*name;

  num = setnbr(nbr);
  if ((name = malloc(sizeof(char) *
		     my_strlen("plane") + my_strlen(num) + 1)) == NULL)
    return (NULL);
  my_bzero(name, my_strlen("plane") + my_strlen(num) + 1);
  my_strcpy(name, "plane");
  my_strcat(name, num);
  bunny_free(num);
  return (name);
}

char	*light_name(UNUSED t_data *data, int nbr)
{
  char	*num;
  char	*name;

  num = setnbr(nbr);
  if ((name = malloc(sizeof(char) *
		     my_strlen("light") + my_strlen(num) + 1)) == NULL)
    return (NULL);
  my_bzero(name, my_strlen("light") + my_strlen(num) + 1);
  my_strcpy(name, "light");
  my_strcat(name, num);
  bunny_free(num);
  return (name);
}
