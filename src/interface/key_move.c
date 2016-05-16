/*
** key_move.c for key in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 18:39:59 2016 bougon_p
** Last update Mon May 16 18:49:24 2016 bougon_p
*/

#include "raytracer.h"

int	move_up(t_data *data)
{
  t_acc vec;

  vec.x = 0;
  vec.y = 300;
  vec.z = 0;
  translation(&data->rt.rotation, &vec,
	      &data->rt.eye.rot,
	      &data->rt.eye.pos);
  return (0);
}

int	move_down(t_data *data)
{
  t_acc vec;

  vec.x = 0;
  vec.y = -300;
  vec.z = 0;
  translation(&data->rt.rotation, &vec,
	      &data->rt.eye.rot,
	      &data->rt.eye.pos);
  return (0);
}

int	move_left(t_data *data)
{
  t_acc vec;

  vec.x = 300;
  vec.y = 0;
  vec.z = 0;
  translation(&data->rt.rotation, &vec,
	      &data->rt.eye.rot,
	      &data->rt.eye.pos);
  return (0);
}

int	move_right(t_data *data)
{
  t_acc vec;

  vec.x = -300;
  vec.y = 0;
  vec.z = 0;
  translation(&data->rt.rotation, &vec,
	      &data->rt.eye.rot,
	      &data->rt.eye.pos);
  return (0);
}
