/*
** move_eye.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 18:34:07 2016 bougon_p
** Last update Tue Apr 26 16:29:11 2016 bougon_p
*/

#include "raytracer.h"

void	move(t_data *data, const t_bunny_position *mpos)
{
  t_acc	vec;

  vec.z = 0;
  if (!data->itfc.move.needmoving)
    {
      data->itfc.move.first_pos = *mpos;
      data->itfc.move.needmoving = true;
    }
  else
    {
      data->itfc.move.second_pos = *mpos;
      vec.x =
	(data->itfc.move.second_pos.x - data->itfc.move.first_pos.x) * 10;
      vec.y =
	(data->itfc.move.second_pos.y - data->itfc.move.first_pos.y) * 10;
      translation(&vec, &data->rt.eye.rot, &data->rt.eye.pos);
      data->itfc.move.first_pos = data->itfc.move.second_pos;
    }
}

void				move_eye(t_data *data)
{
  const t_bunny_position	*mpos;
  t_rt				*rt;

  rt = &data->rt;
  mpos = data->itfc.mpos;
  if (mpos->x > ((((MAX_WORK_SPACE_X - WORK_SPACE_X) / 2) + WORK_SPACE_X) -
  		(rt->img->clipable.clip_width / 2))
      && mpos->x < ((((MAX_WORK_SPACE_X - WORK_SPACE_X) / 2) + WORK_SPACE_X) -
  		    (rt->img->clipable.clip_width / 2) + rt->img->clipable.clip_width)
      && mpos->y > ((((MAX_WORK_SPACE_Y - WORK_SPACE_Y) / 2) + WORK_SPACE_Y) -
  		    (rt->img->clipable.clip_height / 2))
      && mpos->y < ((((MAX_WORK_SPACE_Y - WORK_SPACE_Y) / 2) + WORK_SPACE_Y) -
  		    (rt->img->clipable.clip_height / 2)) + rt->img->clipable.clip_height)
    {
      move(data, mpos);
    }
}
