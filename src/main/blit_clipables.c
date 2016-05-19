/*
** blit_clipables.c for BLIT in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 00:25:51 2016 bougon_p
** Last update Wed May 18 21:31:49 2016 bougon_p
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
    bunny_blit(&data->win->buffer, &rt->img->clipable /*&rt->opt.skybox_backward->clipable*/, &rt->pos);
  if ((data->itfc.button[ADD_FORM] && data->itfc.past.pos.x != 0)
      || (data->itfc.button[GEN_OPT] && data->itfc.past.pos.x != 0))
    bunny_blit(&data->win->buffer, itfc->past.img, &itfc->past.pos);
  if (data->itfc.button[GEN_OPT])
    {
      bunny_blit(&data->win->buffer, itfc->curs, &itfc->gen.pos_curs_aa);
      bunny_blit(&data->win->buffer, itfc->curs, &itfc->gen.pos_curs_amb);
    }
  if (data->itfc.button[SPOTLIGHT])
    bunny_blit(&data->win->buffer, itfc->curs, &itfc->gen.pos_curs_li);
  if ((data->ld.loading != NULL) &&
    (data->itfc.rendered || data->itfc.rendering)
      && !rt->live && !itfc->button[SAVE] && !itfc->button[OPEN]
      && rt->r_pos.x != 0)
    prerender(&data->rt, data->rt.r_pos.y, data);
}
