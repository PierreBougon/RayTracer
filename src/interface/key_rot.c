/*
** key_rot.c for key in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 18:43:04 2016 bougon_p
** Last update Mon May 16 19:01:15 2016 bougon_p
*/

#include "raytracer.h"

int	rot_up(t_data *data)
{
  data->rt.eye.rot.x += 5;
  return (0);
}

int	rot_down(t_data *data)
{
  data->rt.eye.rot.x -= 5;
  return (0);
}

int	rot_left(t_data *data)
{
  data->rt.eye.rot.y -= 5;
  return (0);
}

int	rot_right(t_data *data)
{
  data->rt.eye.rot.y += 5;
  return (0);
}
