/*
** shadow.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 15:49:09 2016 romain samuel
** Last update Sun May 22 15:17:39 2016 marc brout
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

int		shadow_parab(t_rt *s, t_object *obj)
{
  t_parab	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_parab *)obj->datas;
  k = shadow_inter_para(s, shape);
  if (k > 0.000001 && k < 1)
    {
      s->shade.shadow.coef += shape->opacity;
      return (1);
    }
  return (0);
}

int		shadow_hyper(t_rt *s, t_object *obj)
{
  t_hyper	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_hyper *)obj->datas;
  k = shadow_inter_hyper(s, shape);
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
  if ((k = shadow_inter_cone(s, shape)) <= 0)
    return (0);
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
  if ((k = shadow_inter_cylinder(s, shape)) <= 0)
    return (0);
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
  if ((k = shadow_inter_plan(s, shape)) <= 0)
    return (0);
  k = shadow_limited_plan(s, shape, k);
  if (k > 0.000001 && k < 1)
    {
      s->shade.shadow.coef += shape->opacity;
      return (1);
    }
  return (0);
}

int		shadow_box(t_rt *s, t_object *obj)
{
  t_box		*shape;
  t_plan	plan;
  double	k;
  int		i;

  i = 0;
  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_box *)obj->datas;
  while (i < 6)
    {
      plan = shape->plan[i];
      k = shadow_inter_plan(s, &plan);
      if (k > 0)
	{
	  if (s->shade.shadow.simple_inter1.y >= - plan.height &&
	      s->shade.shadow.simple_inter1.y <= plan.height &&
	      s->shade.shadow.simple_inter1.x >= - plan.width &&
	      s->shade.shadow.simple_inter1.x <= plan.width)
	    {
	      s->shade.shadow.coef += shape->opacity;
	      return (1);
	    }
	}
      i++;
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
  s->ftabs.shadow_ftab[4] = NULL;
  s->ftabs.shadow_ftab[5] = &shadow_box;
  s->ftabs.shadow_ftab[6] = NULL;
  s->ftabs.shadow_ftab[7] = &shadow_hyper;
  s->ftabs.shadow_ftab[8] = &shadow_parab;
  s->ftabs.shadow_ftab[9] = NULL;
  it = s->obj;
  s->shade.shadow.coef = 0;
  while (it != NULL)
    {
      if (it->type > 1 && s->ftabs.shadow_ftab[it->type - 1])
	s->ftabs.shadow_ftab[it->type - 1](s, it);
      if (s->shade.shadow.coef >= 1)
	return (1);
      it = it->next;
    }
  return (0);
}
