/*
** shadow_others.c for rt in gfx_raytracer2/src/engine
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 16:21:43 2016 marc brout
** Last update Sun May 22 20:08:49 2016 romain samuel
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

int		shadow_ellipse(t_rt *s, t_object *obj)
{
  t_ellip	*shape;
  double	k;

  if (obj->datas == s->obj_hit->next->datas)
    return (0);
  shape = (t_ellip *)obj->datas;
  k = shadow_inter_ellip(s, shape);
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
