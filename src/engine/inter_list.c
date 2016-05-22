/*
** inter_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat May 14 17:48:07 2016 romain samuel
** Last update Sun May 22 13:28:50 2016 romain samuel
*/

#include "raytracer.h"

int		fill_inter_list_sphere(t_rt *s, t_object *object)
{
  if ((object->inter = create_inter_list()) == NULL)
    return (-1);
  if ((object->inter->next = add_inter_elem(object->inter)) == NULL)
    return (-1);
  object->inter->next->k = s->hit.k1;
  object->inter->next->simple_inter = s->hit.simple_inter1;
  object->inter->next->norm = s->hit.norm1;
  if (s->hit.k2 < 0)
    object->inter->next->exterior = 0;
  else
    {
      object->inter->next->exterior = 1;
      if ((object->inter->next->next = add_inter_elem(object->inter->next))
	  == NULL)
	return (-1);
      object->inter->next->next->exterior = 0;
      object->inter->next->next->k = s->hit.k2;
      object->inter->next->next->simple_inter = s->hit.simple_inter2;
      object->inter->next->next->obj = object;
    }
  object->inter->next->obj = object;
  return (0);
}

int		fill_inter_list_cylinder(t_rt *s,
					 t_object *object)
{
  if ((object->inter = create_inter_list()) == NULL)
    return (-1);
  if ((object->inter->next = add_inter_elem(object->inter)) == NULL)
    return (-1);
  object->inter->next->k = s->hit.k1;
  object->inter->next->simple_inter = s->hit.simple_inter1;
  object->inter->next->norm = s->hit.norm1;
  if (s->hit.k2 < 0)
    object->inter->next->exterior = 0;
  else
    {
      object->inter->next->exterior = 1;
      if ((object->inter->next->next = add_inter_elem(object->inter->next))
	  == NULL)
	return (-1);
      object->inter->next->next->exterior = 0;
      object->inter->next->next->k = s->hit.k2;
      object->inter->next->next->simple_inter = s->hit.simple_inter2;
      object->inter->next->next->obj = object;
    }
  object->inter->next->obj = object;
  return (0);
}

int		fill_inter_list_cone(t_rt *s, t_object *object)
{
  if ((object->inter = create_inter_list()) == NULL)
    return (-1);
  if ((object->inter->next = add_inter_elem(object->inter)) == NULL)
    return (-1);
  object->inter->next->k = s->hit.k1;
  object->inter->next->simple_inter = s->hit.simple_inter1;
  object->inter->next->norm = s->hit.norm1;
  if (s->hit.k2 < 0)
    object->inter->next->exterior = 0;
  else
    {
      object->inter->next->exterior = 1;
      if ((object->inter->next->next = add_inter_elem(object->inter->next))
	  == NULL)
	return (-1);
      object->inter->next->next->exterior = 0;
      object->inter->next->next->k = s->hit.k2;
      object->inter->next->next->simple_inter = s->hit.simple_inter2;
      object->inter->next->next->obj = object;
    }
  object->inter->next->obj = object;
  return (0);
}

int		fill_inter_list_plan(t_rt *s, t_object *object)
{
  if ((object->inter = create_inter_list()) == NULL)
    return (-1);
  if ((object->inter->next = add_inter_elem(object->inter)) == NULL)
    return (-1);
  object->inter->next->k = s->hit.k1;
  object->inter->next->simple_inter = s->hit.simple_inter1;
  object->inter->next->norm = s->hit.norm1;
  object->inter->next->obj = object;
  object->inter->next->exterior = 0;
  return (0);
}

int		fill_inter_list_box(t_rt *s, t_object *object)
{
  if ((object->inter = create_inter_list()) == NULL)
    return (-1);
  if ((object->inter->next = add_inter_elem(object->inter)) == NULL)
    return (-1);
  object->inter->next->k = s->hit.k1;
  object->inter->next->simple_inter = s->hit.simple_inter1;
  object->inter->next->norm = s->hit.norm1;
  if (s->hit.k2 < 0)
    object->inter->next->exterior = 0;
  else
    {
      object->inter->next->exterior = 1;
      if ((object->inter->next->next = add_inter_elem(object->inter->next))
	  == NULL)
	return (-1);
      object->inter->next->next->exterior = 0;
      object->inter->next->next->k = s->hit.k2;
      object->inter->next->next->simple_inter = s->hit.simple_inter2;
      object->inter->next->next->obj = object;
    }
  object->inter->next->obj = object;
  return (0);
}
