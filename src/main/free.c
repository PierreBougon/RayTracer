/*
** free.c for FREE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 22 22:48:42 2016 bougon_p
** Last update Thu Apr 28 00:06:20 2016 bougon_p
*/

#include "raytracer.h"

void	free_all(t_data *data)
{
  free(data->itfc.save.file);
  free(data->itfc.open.file);
}
