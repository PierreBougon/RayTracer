/*
** display_box_csg.c for display_box_csg.c
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun May 22 17:10:43 2016 benjamin duhieu
<<<<<<< HEAD
** Last update Sun May 22 23:19:52 2016 benjamin duhieu
=======
** Last update Sun May 22 22:15:27 2016 romain samuel
>>>>>>> 4532d89b665783de2b64eec582674f48f8d58b58
*/

#include "raytracer.h"

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
      if ((display_csg_objects(s, it->obj)) == -1)
	return (NULL);
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
