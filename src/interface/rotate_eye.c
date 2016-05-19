/*
** rotate_eye.c for rotate in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 18:49:47 2016 bougon_p
** Last update Tue May 17 16:20:49 2016 bougon_p
*/

#include "raytracer.h"

void	rotate(t_data *data, const t_bunny_position *mpos)
{
  if (!data->itfc.move.needmoving)
    {
      data->itfc.move.first_pos = *mpos;
      data->itfc.move.needmoving = true;
    }
  else
    {
      data->itfc.move.second_pos = *mpos;
      data->rt.eye.rot.y = (data->rt.eye.rot.y +
			    ((data->itfc.move.second_pos.x -
			      data->itfc.move.first_pos.x) / 3)) % 360;
      data->rt.eye.rot.x = (data->rt.eye.rot.x -
			    ((data->itfc.move.second_pos.y -
			      data->itfc.move.first_pos.y) / 3)) % 360;
      data->itfc.move.first_pos = data->itfc.move.second_pos;
    }
}

void				rotate_eye(t_data *data)
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
      rotate(data, mpos);
    }
}
