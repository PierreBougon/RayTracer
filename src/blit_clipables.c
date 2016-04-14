/*
** blit_clipables.c for BLIT in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 00:25:51 2016 bougon_p
** Last update Thu Apr 14 02:09:05 2016 bougon_p
*/

#include "raytracer.h"

t_bunny_position	center_rt(t_rt *rt)
{
  t_bunny_position	pos;

  pos.x = (((MAX_WORK_SPACE_X - WORK_SPACE_X) / 2) + WORK_SPACE_X) -
    (rt->img->clipable.clip_width / 2);
  pos.y = (((MAX_WORK_SPACE_Y - WORK_SPACE_Y) / 2) + WORK_SPACE_Y) -
    (rt->img->clipable.clip_height / 2);
  return (pos);
}

void		blit_clipables(t_data *data)
{
  t_rt			*rt;
  t_itfc		*itfc;
  t_bunny_position	rt_pos;

  rt = &data->rt;
  itfc = &data->itfc;
  if (itfc->layout != NULL)
    bunny_blit(&data->win->buffer, &itfc->layout->clipable, 0);
  bunny_blit(&data->win->buffer,
	     &itfc->context[itfc->act_context]->clipable, &itfc->context_pos);
  if (rt->img != NULL)
    {
      rt_pos = center_rt(rt);
      bunny_blit(&data->win->buffer, &rt->img->clipable, &rt_pos);
    }
}
