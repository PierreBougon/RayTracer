/*
** display_csg_objects.c for RAYTRACER

**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue May 17 15:46:36 2016 romain samuel
** Last update Sun May 22 22:52:40 2016 benjamin duhieu
*/

#include "raytracer.h"

int	csg_display_sphere(t_rt *s, t_object *obj)
{
  t_sphere	*shape;

  s->hit.limited = 0;
  shape = (t_sphere *)obj->datas;
  inter_sphere(s, shape);
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
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
      if ((fill_inter_list_sphere(s, obj)) == -1)
	return (-1);
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}

int		csg_display_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*shape;

  s->hit.limited = 0;
  shape = (t_cylinder *)obj->datas;
  if (inter_cylinder(s, shape) == 1)
    return (csg_cylinder_plans_inters(s, shape, obj));
  if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye))
    return(end_rotation(&s->rotation, s->ray.vct, &shape->rot), 0);
  end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  if (limited_cylinder(s, shape) == 0
      && limited_cylinder2(s, shape) == 0 && order_solutions(s) == 0)
    {
      shape->simple_inter1 = s->hit.simple_inter1;
      shape->simple_inter2 = s->hit.simple_inter2;
      shape->k1 = s->hit.k1;
      shape->k2 = s->hit.k2;
      shape->norm1 = s->hit.norm1;
      shape->limited = s->hit.limited;
      if ((fill_inter_list_cylinder(s, obj)) == -1)
	return (-1);
      s->hit.name = obj->name;
    }
  return (0);
}

int		csg_display_cone(t_rt *s, t_object *obj)
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
	  if ((fill_inter_list_cone(s, obj)) == -1)
	    return (-1);
	  s->hit.name = obj->name;
	}
    }
  else
    end_rotation(&s->rotation, s->ray.vct, &shape->rot);
  return (0);
}

int		csg_display_box(t_rt *s, t_object *obj)
{
  t_box		*shape;

  s->hit.limited = 0;
  shape = (t_box *)obj->datas;
  if (inter_box_sides(s, shape) == 0)
    {
      shape->simple_inter1 = s->hit.simple_inter1;
      shape->simple_inter2 = s->hit.simple_inter2;
      shape->k1 = s->hit.k1;
      shape->k2 = s->hit.k2;
      shape->norm1 = s->hit.norm1;
      s->hit.name = obj->name;
      fill_inter_list_box(s, obj);
    }
  return (0);
}

int	display_csg_objects(t_rt *s, t_object *object)
{
  s->ftabs.csg_ftab[0] = &csg_display_sphere;
  s->ftabs.csg_ftab[1] = &csg_display_cylinder;
  s->ftabs.csg_ftab[2] = &csg_display_cone;
  s->ftabs.csg_ftab[3] = &csg_display_box;
  s->hit.k1 = 0.0;
  s->hit.k2 = 0.0;
  if (object->type == 6)
    {
      if ((s->ftabs.csg_ftab[3](s, object)) == -1)
	return (-1);
    }
  else if (object->type > 1 && object->type < 6)
    if ((s->ftabs.csg_ftab[object->type - 2](s, object)) == -1)
      return (-1);
  return (0);
}
