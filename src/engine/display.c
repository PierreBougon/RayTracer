/*
** display.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 17:40:57 2016 romain samuel
** Last update Mon May  2 17:02:16 2016 romain samuel
*/

#include "raytracer.h"

int			inter_objects(t_rt *s)
{
  t_object		*it;

  s->ftabs.inters_ftab[0] = &display_sphere;
  s->ftabs.inters_ftab[1] = &display_cylinder;
  s->ftabs.inters_ftab[2] = &display_cone;
  s->ftabs.inters_ftab[3] = &display_plan;
  it = s->obj;
  while (it != NULL)
    {
      s->hit.k1 = 0.0;
      s->hit.k2 = 0.0;
      if (it->type < 5)
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
  if (s->obj_hit != NULL && s->obj_hit != NULL)
    {
      set_hit_values(s, s->obj_hit->next);
      shade(s, s->ray.vct, s->ray.eye);
      color = s->final_color;
    }
  else
    /* skybox(s, vct); */
    s->final_color.full = BLACK;
  color = s->final_color;
  s->obj_hit = NULL;
  return (color);
}

int			display(t_rt *s)
{
  t_bunny_position	pos;
  t_acc			vct;
  t_color		final_color;

  if ((s->pixel_color = malloc(sizeof(t_color) * s->opt.aa)) == NULL)
    return (my_puterr("display: could not perform malloc"));
  pos.y = 0;
  while (pos.y < 720)
    {
      pos.x = 0;
      while (pos.x < 720)
	{
	  s->rec = 0;
	  final_color = antialiasing(s, &pos, &vct, s->pixel_color);
	  tekpixel(s->img, &pos, &final_color);
	  pos.x++;
	}
      pos.y++;
    }
  return (0);
}
