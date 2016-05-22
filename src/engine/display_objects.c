/*
** display_objects.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 18:02:23 2016 romain samuel
** Last update Sun May 22 20:26:31 2016 romain samuel
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

int		display_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*shape;

  s->hit.limited = 0;
  shape = (t_cylinder *)obj->datas;
  if (inter_cylinder(s, shape) == 1)
    return (cylinder_plans_inters(s, shape, obj));
  else if (get_simple_inter(s, s->ray.vct, &s->ray.new_eye) == 0)
    {
      end_rotation(&s->rotation, s->ray.vct, &shape->rot);
      if (limited_cylinder(s, shape) == 0
	  && limited_cylinder2(s, shape) == 0 && order_solutions(s) == 0)
	{
	  /* printf("k1 = %f, k2 = %f\n", s->hit.k1, s->hit.k2); */
	  /* printf("simple1.x = %f, simple1.y = %f, simple1.z = %f\n", s->hit.simple_inter1.x, s->hit.simple_inter1.y, s->hit.simple_inter1.z); */
	  /* printf("simple2.x = %f, simple2.y = %f, simple2.z = %f\n", s->hit.simple_inter2.x, s->hit.simple_inter2.y, s->hit.simple_inter2.z); */
	  /* printf("limited = %d\n", s->hit.limited); */
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

int		display_box(t_rt *s, t_object *obj)
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
      if ((update_hit_list(s, shape, BOX, s->hit.k1)) == -1)
	return (1);
    }
  return (0);
}

t_csg		*display_tree(t_rt *s, t_csg *it)
{
  if (it->type == 0)
    {
      display_csg_objects(s, it->obj);
      it->inter = it->obj->inter;
    }
  if (it->left != NULL && it->right != NULL)
    {
      if ((it->left = display_tree(s, it->left)) == NULL)
	return (NULL);
      if ((it->right = display_tree(s, it->right)) == NULL)
	return (NULL);
      it->inter = csg_operations(it, it->left->inter, it->right->inter);
    }
  return (it);
}

int		display_csg(t_rt *s, t_object *obj)
{
  t_csg		*shape;
  t_inter	*it;

  s->hit.limited = 0;
  shape = (t_csg *)obj->datas;
  free_tree_inters(shape);
  if (display_tree(s, shape) == NULL)
    return (-1);
  if (shape->inter && shape->inter->next)
    {
      s->hit.k2 = 0.0;
      it = shape->inter->next;
      while (it)
  	{
	  if (it->k > 0.00001)
	    {
	      s->hit.k1 = it->k;
	      return (update_hit_list(s, it->obj->datas,
				      it->obj->type,  it->k));
	    }
	  it = it->next;
	}
    }
  return (0);
}
