/*
** display_objects.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 18:02:23 2016 romain samuel
** Last update Sun May 22 17:23:44 2016 benjamin duhieu
*/

#include "raytracer.h"

int		display_sphere(t_rt *s, t_object *obj)
{
  t_sphere	*shape;

  s->hit.limited = 0;
  shape = (t_sphere *)obj->datas;
  inter_sphere(s, shape);
  if (get_simple_inter(s,s->ray.vct, &s->ray.new_eye) == 0)
    {
      end_rotation(&s->rotation, s->ray.vct, &shape->rot);
      end_rotation(&s->rotation, &s->hit.simple_inter1, &shape->rot);
      get_norm_sphere(s, &s->hit.norm1);
      rotation(&s->rotation, &s->hit.simple_inter1, &shape->rot);
      shape->simple_inter1 = s->hit.simple_inter1;
      shape->simple_inter2 = s->hit.simple_inter2;
      shape->k1 = s->hit.k1;
      shape->k2 = s->hit.k2;
      shape->norm1 = s->hit.norm1;
      s->hit.name = obj->name;
      if ((update_hit_list(s, shape, SPHERE, s->hit.k1)) == -1)
	return (1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}

static int	set_value_cylinder(t_rt *s, t_cylinder *shape,
				   t_object *obj)
{
  end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  if (limited_cylinder(s, shape) == 0
      && limited_cylinder2(s, shape) == 0 && order_solutions(s) == 0)
    {
      shape->simple_inter1 = s->hit.simple_inter1;
      shape->simple_inter2 = s->hit.simple_inter2;
      shape->k1 = s->hit.k1;
      shape->k2 = s->hit.k2;
      shape->norm1 = s->hit.norm1;
      shape->norm2 = s->hit.norm2;
      shape->limited = s->hit.limited;
      s->hit.name = obj->name;
      if ((update_hit_list(s, shape, CYLINDER, s->hit.k1)) == -1)
	return (1);
    }
  return (0);
}

int		display_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*shape;

  s->hit.limited = 0;
  shape = (t_cylinder *)obj->datas;
  if (inter_cylinder(s, shape) == 1)
    return (cylinder_plans_inters(s, shape, obj));
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
    {
      if (set_value_cylinder(s, shape, obj))
	return (1);
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
	  shape->norm1 = s->hit.norm1;
	  shape->limited = s->hit.limited;
	  s->hit.name = obj->name;
	  if ((update_hit_list(s, shape, CONE, s->hit.k1)) == -1)
	    return (1);
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
	  get_norm_plan(s, shape, &s->hit.norm1);
	  shape->simple_inter1 = s->hit.simple_inter1;
	  shape->simple_inter2 = s->hit.simple_inter2;
	  shape->k1 = s->hit.k1;
	  shape->k2 = s->hit.k2;
	  shape->norm = s->hit.norm1;
	  s->hit.name = obj->name;
	  if ((update_hit_list(s, shape, PLANE, s->hit.k1)) == -1)
	    return (1);
	}
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}
