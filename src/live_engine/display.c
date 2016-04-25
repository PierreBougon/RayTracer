/*
** display.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 18 19:05:58 2016 romain samuel
** Last update Mon Apr 25 15:16:17 2016 bougon_p
*/

#include "raytracer.h"
#include "live_engine.h"

t_color			live_display_objects(t_rt *s, t_acc *vct, t_acc eye, int rec)
{
  t_color		color;

  if (rec == 2)
    return (s->final_color);
  s->ray.eye = eye;
  s->ray.vct = vct;
  inter_objects(s);
  order_hit_list(s->obj_hit);
  if (s->obj_hit != NULL && s->obj_hit != NULL)
    {
      set_hit_values(s, s->obj_hit->next);
      live_shade(s, s->ray.vct, s->ray.eye);
      color = s->final_color;
    }
  else
    color.full = BLACK;
  s->obj_hit = NULL;
  return (color);
}

int			live_display(t_rt *s)
{
  t_bunny_position	pos;
  t_acc			vct;
  t_color		final_color;

  if ((s->pixel_color = malloc(sizeof(t_color) * s->opt.aa)) == NULL)
    return (my_puterr("display: could not perform malloc"));
  pos.y = 0;
  while (pos.y < s->height)
    {
      pos.x = 0;
      while (pos.x < s->width)
	{
	  vct.x = ((double)s->width / 2.0) - (double)pos.x;
	  vct.y = ((double)s->height / 2.0) - (double)pos.y;
	  vct.z = 1000;
	  rotation(&vct, &s->eye.rot);
	  final_color = live_display_objects(s, &vct, s->eye.pos, 0);
	  mult_tekpixel(s->img, &pos, &final_color);
	  pos.x += 4;
	}
      pos.y += 4;
    }
  return (0);
}
