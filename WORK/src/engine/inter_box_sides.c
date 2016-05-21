/*
** inter_box_sides.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 15:44:38 2016 romain samuel
** Last update Sat May 21 21:03:07 2016 romain samuel
*/

#include "raytracer.h"

static void	set_box_simple_inter(t_acc *dest,
				     t_acc *src)
{
  dest->x = src->x;
  dest->y = src->y;
  dest->z = src->z;
}

static void	check_box_inters(t_rt *s,
				 t_acc *simple_inter,
				 t_plan *plan,
				 double	k[2])
{
  if (s->hit.k1 > 0.00001 && s->hit.k1 < k[0]
      && simple_inter->y < plan->height && simple_inter->y > - plan->height
      && simple_inter->x < plan->width && simple_inter->x > - plan->width)
    {
      if (k[0] != 10000000)
	{
	  k[1] = k[0];
	  set_box_simple_inter(&s->hit.simple_inter2, &s->hit.simple_inter1);
	}
      k[0] = s->hit.k1;
      set_box_simple_inter(&s->hit.simple_inter1, simple_inter);
      get_norm_plan(s, plan, &s->hit.norm1);
    }
  else if (s->hit.k1 > 0.00001 && s->hit.k1 < k[1]
	   && simple_inter->y < plan->height && simple_inter->y > - plan->height
	   && simple_inter->x < plan->width && simple_inter->x > - plan->width)
    {
      if (s->hit.k1 != k[0])
	{
	  k[1] = s->hit.k1;
	  set_box_simple_inter(&s->hit.simple_inter2, simple_inter);
	}
    }
}

int		inter_box_sides(t_rt *s, t_box *box)
{
  t_plan	plan;
  t_acc		simple_inter;
  int		i;
  double	k[2];

  i = 0;
  k[0] = 10000000;
  k[1] = 10000000;
  while (i < 6)
    {
      s->hit.k1 = -1;
      plan = box->plan[i];
      inter_plan(s, &plan);
      simple_inter.x = s->ray.new_eye.x + s->hit.k1 * s->ray.vct->x;
      simple_inter.y = s->ray.new_eye.y + s->hit.k1 * s->ray.vct->y;
      simple_inter.z = s->ray.new_eye.z + s->hit.k1 * s->ray.vct->z;
      end_rotation(&s->rotation, s->ray.vct, &plan.rot);
      check_box_inters(s, &simple_inter, &plan, k);
      i++;
    }
  if (k[0] == 10000000)
    return (-1);
  s->hit.k1 = k[0];
  s->hit.k2 = k[1];
  return (0);
}
