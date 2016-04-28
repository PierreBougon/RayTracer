/*
** move_eye.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 18:34:07 2016 bougon_p
** Last update Thu Apr 28 16:29:50 2016 bougon_p
*/

#include "raytracer.h"

/*
** Fuction call from my_wheel on wheel event
** Move on x axe from a vector 300 on x
*/
void	move_on_wheel(t_data *data, int wheelid, int delta)
{
  t_acc	vec;

  vec.x = 300;
  vec.y = 0;
  vec.z = 0;
  if (delta == 1 && wheelid == 1)
    translation(&vec, &data->rt.eye.rot, &data->rt.eye.pos);
  else if (delta == -1 && wheelid == 1)
    {
      vec.x = -300;
      translation(&vec, &data->rt.eye.rot, &data->rt.eye.pos);
    }
}

/*
** Those functions are use to move the eye's position
** From the status movement in the top bar
** Calc a coef from 2 pos of the mouse
** To set a vector then eye take this new position
*/
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
