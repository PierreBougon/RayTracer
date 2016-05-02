/*
** display_objects.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 18:02:23 2016 romain samuel
** Last update Mon May  2 19:05:00 2016 romain samuel
*/

#include "raytracer.h"

int		display_sphere(t_rt *s, t_object *obj)
{
  t_sphere	*shape;

  s->hit.limited = 0;
  shape = (t_sphere *)obj->datas;
  inter_sphere(s, shape);
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
    {
      end_rotation(&s->rotation, s->ray.vct, &shape->rot);
      end_rotation(&s->rotation, &s->hit.simple_inter1, &shape->rot);
      get_norm_sphere(s);
      rotation(&s->rotation, &s->hit.simple_inter1, &shape->rot);
      shape->simple_inter1 = s->hit.simple_inter1;
      shape->simple_inter2 = s->hit.simple_inter2;
      shape->k1 = s->hit.k1;
      shape->k2 = s->hit.k2;
      shape->norm = s->hit.norm;
      update_hit_list(s, shape, 1, s->hit.k1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}

int		display_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*shape;

  s->hit.limited = 0;
  shape = (t_cylinder *)obj->datas;
  inter_cylinder(s, shape);
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
    {
      end_rotation(&s->rotation, s->ray.vct, &shape->rot);
      if (limited_cylinder(s, shape) == 0)
	{
	  shape->simple_inter1 = s->hit.simple_inter1;
	  shape->simple_inter2 = s->hit.simple_inter2;
	  shape->k1 = s->hit.k1;
	  shape->k2 = s->hit.k2;
	  shape->norm = s->hit.norm;
	  shape->limited = s->hit.limited;
	  update_hit_list(s, shape, 2, s->hit.k1);
	}
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}

int		display_cone(t_rt *s, t_object *obj)
{
  t_cone	*shape;

  s->hit.limited = 0;
  shape = (t_cone *)obj->datas;
  inter_cone(s, shape);
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
    {
      end_rotation(&s->rotation, s->ray.vct, &shape->rot);
      if (limited_cone(s, shape) == 0)
	{
	  shape->simple_inter1 = s->hit.simple_inter1;
	  shape->simple_inter2 = s->hit.simple_inter2;
	  shape->k1 = s->hit.k1;
	  shape->k2 = s->hit.k2;
	  shape->norm = s->hit.norm;
	  shape->limited = s->hit.limited;
	  update_hit_list(s, shape, 3, s->hit.k1);
	}
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}

int		display_plan(t_rt *s, t_object *obj)
{
  t_plan	*shape;

  s->hit.limited = 0;
  shape = (t_plan *)obj->datas;
  inter_plan(s, shape);
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
    {
      end_rotation(&s->rotation, s->ray.vct, &shape->rot);
      if (limited_plan(s, shape) == 0)
	{
	  get_norm_plan(s, shape);
	  shape->simple_inter1 = s->hit.simple_inter1;
	  shape->simple_inter2 = s->hit.simple_inter2;
	  shape->k1 = s->hit.k1;
	  shape->k2 = s->hit.k2;
	  shape->norm = s->hit.norm;
	  update_hit_list(s, shape, 4, s->hit.k1);
	}
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}
