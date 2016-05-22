/*
** move_spot.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 17 14:50:20 2016 bougon_p
** Last update Sun May 22 14:07:53 2016 bougon_p
*/

#include "raytracer.h"

static	void	move_light(t_data *data,
			   const t_bunny_position *mpos)
{
  t_acc		vec;
  t_light	*light;
  t_pos		*pos;

  vec.z = 0;
  if (!data->itfc.obj_click || !data->itfc.light_selected)
    return ;
  if (!data->itfc.move.needmoving)
    {
      data->itfc.move.first_pos = *mpos;
      data->itfc.move.needmoving = true;
    }
  else
    {
      light = data->itfc.light_selected->datas;
      pos = &light->pos;
      data->itfc.move.second_pos = *mpos;
      vec.x =
        -((data->itfc.move.second_pos.x - data->itfc.move.first_pos.x) * 35);
      vec.y =
        -((data->itfc.move.second_pos.y - data->itfc.move.first_pos.y) * 35);
      translation_obj(&data->rt.rotation, &vec,
		      &data->rt.eye.rot, pos);
      data->itfc.move.first_pos = data->itfc.move.second_pos;
    }
}

int				move_spot(t_data *data)
{
  const	t_bunny_position	*mpos;
  t_rt				*rt;

  rt = &data->rt;
  mpos = data->itfc.mpos;
  if (check_workspace(mpos, rt))
    {
      move_light(data, mpos);
    }
  return (0);
}
