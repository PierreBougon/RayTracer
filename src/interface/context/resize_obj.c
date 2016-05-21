/*
** resize_obj.c for resize in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 20 15:32:40 2016 bougon_p
** Last update Sat May 21 16:00:06 2016 bougon_p
*/

#include "raytracer.h"

static int			calc_coef(t_data *data)
{
  t_acc			vec;
  t_bunny_position	mpos;

  mpos = *data->itfc.mpos;
  vec.z = 0;
  if (!data->itfc.move.needmoving)
    {
      data->itfc.move.first_pos = mpos;
      data->itfc.move.needmoving = true;
    }
  else
    {
      data->itfc.move.second_pos = mpos;
      vec.x =
        ((data->itfc.move.second_pos.x - data->itfc.move.first_pos.x) * 3);
      vec.y =
        -((((data->itfc.move.second_pos.y))
	   - (data->itfc.move.first_pos.y)) * 3.0);
      data->itfc.
	fct_resize[data->itfc.obj_selected->type - 1](data, &vec);
      data->itfc.move.first_pos = data->itfc.move.second_pos;
    }
  return (0);
}

int	resize_obj(t_data *data)
{
  if (check_workspace(data->itfc.mpos, &data->rt) &&
      (data->itfc.obj_click && data->itfc.obj_selected))
    calc_coef(data);
  return (0);
}
