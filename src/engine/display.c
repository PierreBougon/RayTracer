/*
** display.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 17:40:57 2016 romain samuel
** Last update Mon May 16 19:23:56 2016 benjamin duhieu
*/

#include "raytracer.h"

int			inter_objects(t_rt *s)
{
  t_object		*it;

  s->ftabs.inters_ftab[0] = &display_sphere;
  s->ftabs.inters_ftab[1] = &display_cylinder;
  s->ftabs.inters_ftab[2] = &display_cone;
  s->ftabs.inters_ftab[3] = &display_plan;
  s->ftabs.inters_ftab[4] = &display_tore;
  s->ftabs.inters_ftab[5] = &display_box;
  it = s->obj;
  while (it != NULL)
    {
      s->hit.k1 = 0.0;
      s->hit.k2 = 0.0;
      if (it->type != LIGHT)
	s->ftabs.inters_ftab[it->type - 1](s, it);
      it = it->next;
    }
  return (0);
}

t_color			display_objects(t_rt *s, t_acc *vct, t_acc eye)
{
  t_color		color;

  if (s->rec == 2)
    {
      s->rec = 0;
      return (s->final_color);
    }
  s->ray.eye = eye;
  s->ray.vct = vct;
  inter_objects(s);
  order_hit_list(s->obj_hit);
  if (s->obj_hit != NULL && s->obj_hit->next != NULL)
    {
      set_hit_values(s, s->obj_hit->next);
      shade(s, s->ray.vct, s->ray.eye);
      color = s->final_color;
      clear_list(s->obj_hit);
      s->obj_hit = NULL;
    }
  else
    skybox(s, vct);
  color = s->final_color;
  return (color);
}

void	prerender(t_rt *rt, int y, t_data *data)
{
  if (y == 0)
    data->ld.loading->clipable.clip_width = 1;
  else if (y % (int)rt->coef_load == 0)
    {
      data->ld.curr_line += LOADING_COEF;
      data->ld.loading->clipable.clip_width = data->ld.curr_line;
      data->ld.nb_coef++;
    }
  if (y > rt->coef_load * rt->nb_coef)
    rt->nb_coef++;
  bunny_blit(&data->win->buffer,
	     &data->ld.loading->clipable, &data->ld.pos);
}

int			display(t_rt *s, t_data *data)
{
  t_acc			vct;
  t_color		final_color;

  if (s->r_pos.y < s->height)
    {
      s->r_pos.x = 0;
      while (s->r_pos.x < s->width)
	{
	  s->rec = 0;
	  final_color = antialiasing(s, &s->r_pos, &vct, s->pixel_color);
	  tekpixel(s->img, &s->r_pos, &final_color);
	  s->r_pos.x++;
	}
      s->r_pos.y++;
    }
  if (s->r_pos.y == s->height)
    {
      data->itfc.rendering = false;
      data->itfc.rendered = true;
      data->ld.loading->clipable.clip_width = data->ld.save_width;
      bunny_free(s->shade.itab);
    }
  return (0);
}
