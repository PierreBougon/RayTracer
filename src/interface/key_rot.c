/*
** key_rot.c for key in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 18:43:04 2016 bougon_p
** Last update Tue May 17 16:16:14 2016 bougon_p
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
  data->rt.eye.rot.y = (data->rt.eye.rot.y - 3) % 360;;
  return (0);
}

int	rot_right(t_data *data)
{
  data->rt.eye.rot.y = (data->rt.eye.rot.y + 3) % 360;;
  return (0);
}
