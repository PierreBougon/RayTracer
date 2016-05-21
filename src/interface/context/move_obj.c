/*
** move_obj.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 20 15:33:32 2016 bougon_p
** Last update Fri May 20 21:17:03 2016 bougon_p
*/

#include "raytracer.h"

static	void			move_object(t_data *data)
{
  t_acc				vec;
  t_pos				*pos;
  t_bunny_position		mpos;

  mpos = *data->itfc.mpos;
  vec.z = 0;
  if (!data->itfc.move.needmoving)
    {
      data->itfc.move.first_pos = mpos;
      data->itfc.move.needmoving = true;
    }
  else
    {
      pos = (t_pos *)data->itfc.obj_selected->datas;
      data->itfc.move.second_pos = mpos;
      vec.x =
        -((data->itfc.move.second_pos.x - data->itfc.move.first_pos.x) * 10);
      vec.y =
        -((data->itfc.move.second_pos.y - data->itfc.move.first_pos.y) * 10);
      translation_obj(&data->rt.rotation, &vec,
                      &data->rt.eye.rot, pos);
      data->itfc.move.first_pos = data->itfc.move.second_pos;
    }
}

int	move_obj(t_data *data)
{
  data->itfc.obj_selected = data->rt.obj;


  if (check_workspace(data->itfc.mpos, &data->rt) &&
      (data->itfc.obj_click && data->itfc.obj_selected))
    {
      move_object(data);
    }
  return (0);
}
