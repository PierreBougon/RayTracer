/*
** display.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 17:40:57 2016 romain samuel
** Last update Wed Apr 13 21:57:47 2016 bougon_p
*/

#include "raytracer.h"

int			inter_objects(t_rt *s)
{
  int			(**ftab)(t_rt *, t_object *);
  t_object		*it;

  if ((ftab = malloc(sizeof(ftab) * 4)) == NULL)
    return (my_puterr("inter_objects: could not perform bunny_malloc"));
  ftab[0] = &display_sphere;
  ftab[1] = &display_cylinder;
  ftab[2] = &display_cone;
  ftab[3] = &display_plan;
  it = s->obj;
  while (it != NULL)
    {
      s->hit.k1 = 0;
      s->hit.k2 = 0;
      if (it->type < 5)
	ftab[it->type - 1](s, it);
      it = it->next;
    }
  return (0);
}

t_color			display_objects(t_rt *s, t_acc *vct, t_acc eye, int rec)
{
  t_color		color;

  if (rec == 2)
    return (s->final_color);
  s->ray.eye = eye;
  s->ray.vct = vct;
  inter_objects(s);
  order_hit_list(s->obj_hit);
  if (s->obj_hit != NULL && s->obj_hit->next != NULL)
    {
      set_hit_values(s, s->obj_hit->next);
      shade(s, s->ray.vct, s->ray.eye);
      color = s->final_color;
    }
  else
    color.full = BLACK;
  s->obj_hit = NULL;
  return (color);
}

int			display(t_rt *s)
{
  t_bunny_position	pos;
  t_acc			vct;
  t_color		*color;
  t_color		final_color;

  if ((color = malloc(sizeof(t_color) * s->opt.aa)) == NULL)
    return (my_puterr("display: could not perform malloc"));
  pos.y = 0;
  while (pos.y < 720)
    {
      pos.x = 0;
      while (pos.x < 720)
	{
	  final_color = antialiasing(s, &pos, &vct, color);
	  tekpixel(s->img, &pos, &final_color);
	  pos.x++;
	}
      pos.y++;
    }
  return (0);
}
