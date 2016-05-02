/*
** shadow.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 15:49:09 2016 romain samuel
** Last update Sat Apr 23 18:19:58 2016 romain samuel
*/

#include "raytracer.h"

int		shadow_sphere(t_rt *s, t_object *obj)
{
  t_sphere	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_sphere *)obj->datas;
  k = shadow_inter_sphere(s, shape);
  if (k > 0.000001 && k < 1)
    {
      s->shade.shadow.coef += shape->opacity;
      return (1);
    }
  return (0);
}

int		shadow_cone(t_rt *s, t_object *obj)
{
  t_cone	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_cone *)obj->datas;
  k = shadow_inter_cone(s, shape);
  k = shadow_limited_cone(s, shape, k);
  if (k > 0.000001 && k < 1)
    {
      s->shade.shadow.coef += shape->opacity;
      return (1);
    }
  return (0);
}

int		shadow_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_cylinder *)obj->datas;
  k = shadow_inter_cylinder(s, shape);
  k = shadow_limited_cylinder(s, shape, k);
  if (k > 0.000001 && k < 1)
    {
      s->shade.shadow.coef += shape->opacity;
      return (1);
    }
  return (0);
}

int		shadow_plan(t_rt *s, t_object *obj)
{
  t_plan	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_plan *)obj->datas;
  k = shadow_inter_plan(s, shape);
  if (k > 0.000001 && k < 1)
    {
      s->shade.shadow.coef += shape->opacity;
      return (1);
    }
  return (0);
}

int			shadow(t_rt *s)
{
  t_object		*it;

  s->ftabs.shadow_ftab[0] = &shadow_sphere;
  s->ftabs.shadow_ftab[1] = &shadow_cylinder;
  s->ftabs.shadow_ftab[2] = &shadow_cone;
  s->ftabs.shadow_ftab[3] = &shadow_plan;
  it = s->obj;
  s->shade.shadow.coef = 0;
  while (it != NULL)
    {
      if (it->type < 5)
	s->ftabs.shadow_ftab[it->type - 1](s, it);
      if (s->shade.shadow.coef >= 1)
	return (1);
      it = it->next;
    }
  return (0);
}
