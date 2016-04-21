/*
** blit_clipables.c for BLIT in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 00:25:51 2016 bougon_p
** Last update Thu Apr 21 12:06:39 2016 bougon_p
*/

#include "raytracer.h"

void		blit_clipables(t_data *data)
{
  t_rt			*rt;
  t_itfc		*itfc;

  rt = &data->rt;
  itfc = &data->itfc;
  if (itfc->layout != NULL)
    bunny_blit(&data->win->buffer, itfc->layout, 0);
  bunny_blit(&data->win->buffer,
	     itfc->context[itfc->act_context], &itfc->context_pos);
  if (rt->img != NULL)
    bunny_blit(&data->win->buffer, &rt->img->clipable, &rt->pos);
  if (data->ld.loading != NULL && data->itfc.rendered && !rt->live)
    bunny_blit(&data->win->buffer,
	       &data->ld.loading->clipable, &data->ld.pos);
}
