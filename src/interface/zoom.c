/*
** zoom.c for zoom in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 16:21:28 2016 bougon_p
** Last update Mon May  2 17:06:52 2016 marc brout
*/

#include "raytracer.h"

/*
** Function called from my_wheel on wheel event
** Set a vector in front of the eye then go on the
** New position
*/
void	zoom(t_data *data, int wheelid, int delta)
{
  t_acc	vec;

  vec.x = 0;
  vec.y = 0;
  vec.z = 500;
  if (delta == 1 && wheelid == 0)
    translation(&data->rt.rotation,
		&vec,
		&data->rt.eye.rot,
		&data->rt.eye.pos);
  else if (delta == -1 && wheelid == 0)
    {
      vec.z = -500;
      translation(&data->rt.rotation,
		  &vec, &data->rt.eye.rot,
		  &data->rt.eye.pos);
    }
}
