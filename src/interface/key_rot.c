/*
** key_rot.c for key in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 18:43:04 2016 bougon_p
** Last update Sun May 22 21:56:12 2016 romain samuel
*/

#include "raytracer.h"

int	rot_up(t_data *data)
{
  data->rt.eye.rot.x = (data->rt.eye.rot.x + 3) % 360;
  return (0);
}

int	rot_down(t_data *data)
{
  data->rt.eye.rot.x = (data->rt.eye.rot.x - 3) % 360;
  return (0);
}

int	rot_left(t_data *data)
{
  data->rt.eye.rot.y = (data->rt.eye.rot.y - 3) % 360;
  return (0);
}

int	rot_right(t_data *data)
{
  data->rt.eye.rot.y = (data->rt.eye.rot.y + 3) % 360;
  return (0);
}
