/*
** blit_clipables.c for BLIT in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 00:25:51 2016 bougon_p
** Last update Sun May 22 17:11:43 2016 marc brout
*/

#include "raytracer.h"

static void		aff_tex_state(t_data *data)
{
  t_itfc		*itfc;
  t_bunny_position	pos;

  if (data->itfc.obj_selected && data->itfc.button[MODIF_FORM])
    {
      itfc = &data->itfc;
      pos.x = MOD_RAD_X + 4;
      if (itfc->past.rad_state == FLAT)
	pos.y = MOD_RAD_Y + 9;
      else if (itfc->past.rad_state == PERLIN)
	pos.y = MOD_RAD_Y + MOD_RAD_DECAL + MOD_RAD_HGT + 9;
      else if (itfc->past.rad_state == IMG)
	pos.y = MOD_RAD_Y + 2 * (MOD_RAD_DECAL + MOD_RAD_HGT) + 9;
      bunny_blit(&data->win->buffer, itfc->past.img, &pos);
    }
}

static void		aff_refl_state(t_data *data)
{
  t_itfc		*itfc;
  t_bunny_position	pos;

  if (data->itfc.obj_selected && data->itfc.button[MODIF_FORM])
    {
      itfc = &data->itfc;
      pos.y = MOD_REFL_Y - 2;
      if (itfc->past.refl_state == YES)
	pos.x = MOD_REFL_X + 1;
      else if (itfc->past.refl_state == NO)
	pos.x = MOD_REFL_X + MOD_REFL_DECAL + 3;
      bunny_blit(&data->win->buffer, itfc->past.img, &pos);
    }
}

static void		blit_suite(t_data *data)
{
  t_rt			*rt;
  t_itfc		*itfc;

  rt = &data->rt;
  itfc = &data->itfc;
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
      && rt->r_pos.x)
    prerender(&data->rt, data->rt.r_pos.y, data);
}

void			blit_clipables(t_data *data)
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
    bunny_blit(&data->win->buffer, &rt->img->clipable , &rt->pos);
  if ((data->itfc.button[ADD_FORM] && data->itfc.past.pos.x != 0)
      || (data->itfc.button[GEN_OPT] && data->itfc.past.pos.x != 0))
    bunny_blit(&data->win->buffer, itfc->past.img, &itfc->past.pos);
  aff_tex_state(data), aff_refl_state(data);
  blit_suite(data);
}
