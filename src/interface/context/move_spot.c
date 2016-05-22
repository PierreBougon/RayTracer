/*
** move_spot.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 17 14:50:20 2016 bougon_p
** Last update Sun May 22 22:05:28 2016 benjamin duhieu
*/

#include "raytracer.h"

static	void	move_light(t_data *d,
			   const t_bunny_position *mpos)
{
  t_acc		vec;
  t_light	*light;
  t_pos		*pos;

  vec.z = 0;
  if (!d->itfc.obj_click || !d->itfc.light_selected)
    return ;
  if (!d->itfc.move.needmoving)
    {
      d->itfc.move.first_pos = *mpos;
      d->itfc.move.needmoving = true;
    }
  else
    {
      light = d->itfc.light_selected->datas;
      pos = &light->pos;
      d->itfc.move.second_pos = *mpos;
      vec.x =
        -((d->itfc.move.second_pos.x - d->itfc.move.first_pos.x) * 35);
      vec.y =
        -((d->itfc.move.second_pos.y - d->itfc.move.first_pos.y) * 35);
      translation_obj(&d->rt.rotation, &vec,
		      &d->rt.eye.rot, pos);
      d->itfc.move.first_pos = d->itfc.move.second_pos;
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
